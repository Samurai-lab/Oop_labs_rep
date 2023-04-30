#include "FileIO.h"
#include "windows.h"

#define SAVE_VARIBLE_NAME(varible) VARIBLE_NAME = std::string(#varible) + ".txt";

Pair &operator+(int n, Pair &pair) {
    return pair + n;
}

Pair &operator+(double n, Pair &pair) {
    return pair + n;
}

std::string VARIBLE_NAME = "NULL";

void fun_int() {
    LinkedList<double> list(3, 1.5);
    SAVE_VARIBLE_NAME(list2);
    FileIO<double> file(VARIBLE_NAME);
    list.push(1.7);
    list.push(2.1);
    list.push(2.5);

    std::cout << "\n" << VARIBLE_NAME << " download in file: " << std::endl;
    std::cout << list << std::endl;
    file.load(list);

    std::cout << "\n" << VARIBLE_NAME << " decrease for 0,5: " << std::endl;
    file.decrease_records(0.5);
    if (file.unload() != -1)
        std::cout << file.give_list();

    std::cout << "\n" << VARIBLE_NAME << " delete if decrease than 1.6: " << std::endl;
    file.del_less_than(1.6);
    if (file.unload() != -1)
        std::cout << file.give_list();

    int n, k;
    std::cout << "\n" << VARIBLE_NAME << " add after n= element k=" << std::endl;
    std::cin >> n >> k;
    file.add_records(n, k);
    if (file.unload() != -1)
        std::cout << file.give_list();
}

void fun_Pair() {
    LinkedList<Pair> list(3, Pair(1, 1));
    SAVE_VARIBLE_NAME(list2);
    FileIO<Pair> file(VARIBLE_NAME);
    list.push(Pair(1, 1.7));
    list.push(Pair(2, 2.1));
    list.push(Pair(3, 2.5));

    std::cout << "\n" << VARIBLE_NAME << " download in file: " << std::endl;
    std::cout << list << std::endl;
    file.load(list);

    std::cout << "\n" << VARIBLE_NAME << " decrease for Pair(2,0.3) " << std::endl;
    file.decrease_records(Pair(2, 0.3));
    if (file.unload() != -1)
        std::cout << file.give_list();

    std::cout << "\n" << VARIBLE_NAME << " delete if decrease for Pair(1, 0.5) " << std::endl;
    file.del_less_than(Pair(0, 1.4));
    if (file.unload() != -1)
        std::cout << file.give_list();

    int n, k;
    std::cout << "\n" << VARIBLE_NAME << " add after n= element k=" << std::endl;
    std::cin >> n >> k;
    file.add_records(n, k);
    if (file.unload() != -1)
        std::cout << file.give_list();
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    fun_Pair();

    return 0;
}
