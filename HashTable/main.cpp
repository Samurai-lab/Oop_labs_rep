#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include "HashTable.h"


int main() {
    srand(time(nullptr));
    setlocale(LC_ALL, "Rus");
    HashTable hashTable;
    int flag = 0;
    while (flag < 8) {
        std::cout << "Выберите номер команды:"
                "\n1. Создать Хеш-таблицу"
                "\n2. Показать Хеш-таблицу"
                "\n3. Удалить из Хеш-таблицы элемент с выбранной датой рождения"
                "\n4. Восстановить Хеш-таблицу из файла"
                "\n5. Найти номер элемента в Хеш-таблице по дате рождения"
                "\n6. Записать Хеш-таблицу в файл"
                "\n7. Добавить элемент в Хеш-таблицу\n"
                "\n8. Exit from application\n";
        std::cin >> flag;
        system("cls");
        switch (flag) {
            case (1):
                hashTable.createHash();
                break;
            case (2):
                hashTable.showHash();
                break;
            case (3):
                hashTable.deleteFromHash();
                break;
            case (4):
                hashTable.readHash();
                break;
            case (5):
                hashTable.fIHFindIntoHash();
                break;
            case (6):
                hashTable.writeHash();
                break;
            case (7):
                hashTable.addElement();
                break;
            default:
                flag = 8;
        }
    }
}