#include "Dialog.h"
#include <iostream>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Menu" << std::endl << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl << "1. Creating vector: (m6, where - 6 it's size)\n"
                              "2. Add element: +\n"
                              "3. Delete element: -\n"
                              "4. Display element's lines: s\n"
                              "5. Middle age: z\n"
                              "6. Exit: q\n\n";
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    Dialog D;
    D.Execute();
    return 0;
}
