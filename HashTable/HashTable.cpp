#include "HashTable.h"

struct Human {
    char fio[255];
    char dateofbirth[255];
    char number[255];
};

struct Node {
    Human human;
    Node *next;
};

struct LinkedList {
    Node *last, *current, *head;
};

std::string f[5] = {"Антонов", "Мельников", "Бойков", "Молов", "Шилов"};
std::string i[5] = {"Герман", "Глеб", "Артём", "Андрей", "Валерий"};
std::string o[5] = {"Владимирович", "Денисович", "Андреевич", "Глебович", "Николаевич"};
std::string d[5] = {"12.04.12", "12.08.10", "01.03.03", "07.09.02", "03.09.06"};
std::string p[5] = {"678544", "783353", "765791", "766872", "986551"};
int n = 0;
char date[255];
FILE *file;

LinkedList *m = new LinkedList;

void HashTable::changeValue(char *c, std::string r) {
    for (int k = 0; k < r.length(); k++) {
        c[k] = r[k];
    }
    c[r.length()] = '\0';
}

int HashTable::randomNuberSensor() {
    int rand = 0;
    rand = rand % 5;
    return rand;
}

int HashTable::getPosibleKey() {
    double key = 0;
    for (int k = 0; k < 9; k += 3) {
        std::string s;
        s += date[k];
        s += date[k + 1];
        key += stoi(s);
    }
    key *= 0.75;
    key -= (int) key;
    return (int) (n * key);
}

void HashTable::createHash() {
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    auto *t = new LinkedList[n]{};
    int collision = 0;
    for (int k = 0; k < n; k++) {
        changeValue(date, d[randomNuberSensor()]);
        int l = getPosibleKey();
        bool occupied = t[l].head != nullptr;
        t[l].current = t[l].head;
        if (occupied) {
            while (t[l].current->next != nullptr) {
                t[l].current = t[l].current->next;
            }
        }
        Node *q = new Node;
        changeValue(q->human.fio, f[randomNuberSensor()] + ' ' + i[randomNuberSensor()] + ' ' + o[randomNuberSensor()]);
        changeValue(q->human.dateofbirth, date);//работает :)
        changeValue(q->human.number, p[randomNuberSensor()]);
        if (occupied) {
            collision++;
            t[l].current->next = q;
            t[l].current->next->next = nullptr;
        } else {
            t[l].head = q;
            t[l].head->next = nullptr;
        }
    }
    delete m;
    m = t;
    std::cout << "Хеш-таблица создана! " << "Коллизий: " << collision << '\n';
}

void HashTable::deleteFromHash() {
    if (n) {
        std::cout << "Введите дату: ";
        std::cin.getline(date, 255);
        std::cin >> date;
        for (int k = 0; k < n; k++) {
            m[k].current = m[k].head;
            while (m[k].current != nullptr) {
                if (!strcmp(m[k].current->human.dateofbirth, date)) {
                    changeValue(m[k].current->human.fio, "NULL");
                    changeValue(m[k].current->human.dateofbirth, "NULL");
                    changeValue(m[k].current->human.number, "NULL");
                }
                m[k].current = m[k].current->next;
            }
        }
    } else {
        std::cout << "Хеш-таблица пуста!\n";
    }
}

void HashTable::fIHFindIntoHash() {
    if (n) {
        std::cin.get();
        std::cout << "Введите дату: ";
        std::cin.getline(date, 255);
        int l = getPosibleKey();
        for (int k = 0; k < n; k++) {
            m[l].current = m[l].head;
            while (m[l].current != nullptr) {
                if (!strcmp(m[l].current->human.dateofbirth, date)) {
                    std::cout << l + 1 << '\n';
                    return;
                }
                m[l].current = m[l].current->next;
            }
            l = (l + 1) % n;
        }
        std::cout << "-1\n";
    } else {
        std::cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void HashTable::addElement() {
    int l;
    std::cout << "Введите номер нового элемента: ";
    std::cin >> l;
    Node *q = new Node;///генерирую новый элемент
    changeValue(q->human.fio, f[randomNuberSensor()] + ' ' + i[randomNuberSensor()] + ' ' + o[randomNuberSensor()]);//
    changeValue(q->human.dateofbirth, d[randomNuberSensor()]);//
    changeValue(q->human.number, p[randomNuberSensor()]);///
    if (l > n) {//если новый элемент должен находиться в ещё несуществующем ключе, то нужно изменить размер массива
        auto *t = new LinkedList[l]{};//создаём новый массив
        for (int k = 0; k < n; k++) {
            t[k] = m[k];//передаём значения из старого
        }
        delete m;
        m = t;
        n = l;
        q->next = nullptr;//должен указывать на NULL, так как первый элемент под данным ключом
        m[l - 1].head = q;//задаём новый элемент в получивщийся массив, в новую ячейку
    } else if (m[l - 1].head != nullptr && strcmp(m[l - 1].head->human.fio,
                                                  "NULL") !=
                                           0) {//если первый элемент под нужным ключом не NULL и не помечен как удалённый ("NULL")
        m[l - 1].current = m[l - 1].head;//устанавливаем текущий на голову
        while (m[l - 1].current->next != nullptr &&
               strcmp(m[l - 1].current->next->human.fio, "NULL") != 0) {//пока следующий не NULL или "NULL"
            m[l - 1].current = m[l - 1].current->next;//получаю следующий
        }
        if (m[l - 1].current->next == nullptr) {//если слудующий NULL
            q->next = nullptr;//обращаться должен на NULL, так как конец списка
        } else {//если "NULL"
            q->next = m[l - 1].current->next->next;//обращается на следующий->следующий элемент
        }
        m[l - 1].current->next = q;//меняем значение следующего элемента
    } else {//если сразу NULL или "NULL"
        if (m[l - 1].head == nullptr) {
            q->next = nullptr;//обращается на NULL, так как конец списка
            m[l - 1].head = q;//задаём голове значение
        } else {//если "NULL"
            q->next = m[l - 1].head->next;//задаём значение слудующего
            m[l - 1].head = q;//задаём значение голове
        }
    }
}

void HashTable::showHash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            if (m[k].head != nullptr) {
                std::cout << "Ключ " << k << ":\n";
                m[k].current = m[k].head;
                while (m[k].current != nullptr) {
                    std::cout << m[k].current->human.fio << ' ' << m[k].current->human.dateofbirth << ' '
                              << m[k].current->human.number << '\n';
                    m[k].current = m[k].current->next;
                }
            }
        }
        std::cout << "-------------------------------\n";
    } else {
        std::cout << "Хеш-таблица пуста!\n";
    }
}

void HashTable::writeHash() {
    if (n) {
        file = fopen("Hash.txt", "wb");
        fwrite(&n, sizeof(n), 1, file);
        char space = ' ';
        char newline = 'h';
        fwrite(&newline, sizeof(newline), 1, file);
        for (int k = 0; k < n; k++) {
            m[k].current = m[k].head;
            while (m[k].current != nullptr) {
                fwrite(&space, sizeof(space), 1, file);
                fwrite(&m[k].current->human, sizeof(Human), 1, file);
                m[k].current = m[k].current->next;
            }
            fwrite(&newline, sizeof(newline), 1, file);
        }
        fclose(file);
    } else {
        std::cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void HashTable::readHash() {
    if ((file = fopen("Hash.txt", "rb")) == nullptr) {
        std::cout << "Ошибка чтения файла\n";
    } else if (!feof(file)) {
        fread(&n, sizeof(n), 1, file);
        auto *t = new LinkedList[n]{};
        char c;
        fread(&c, sizeof(c), 1, file);
        for (int k = 0; k < n; k++) {
            fread(&c, sizeof(c), 1, file);
            if (c == ' ') {
                Node *q = new Node;
                fread(&q->human, sizeof(Human), 1, file);
                t[k].current = t[k].head = q;
                t[k].current->next = nullptr;
                fread(&c, sizeof(c), 1, file);
                while (c != 'h') {
                    Node *pNode = new Node;
                    fread(&pNode->human, sizeof(Human), 1, file);
                    t[k].current->next = pNode;
                    t[k].current = t[k].current->next;
                    t[k].current->next = nullptr;
                    fread(&c, sizeof(c), 1, file);
                }
            }
        }
        delete m;
        m = t;
        fclose(file);
    } else {
        std::cout << "Файл пуст, операция не возможна!\n";
        fclose(file);
    }
}















