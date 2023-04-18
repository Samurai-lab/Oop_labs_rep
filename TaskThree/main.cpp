#include <iostream>
#include "Pair.h"

int main() {
    Pair pairOne;
    Pair pairTwo(1, 2.0);
    Pair pairThree(pairTwo);

    std::cout << pairOne;
    std::cout << pairTwo;
    std::cout << pairThree;

    pairTwo.pairSubtraction(2, 3);

    std::cout << pairTwo;

    pairTwo.setFirst(4);
    pairTwo.setSecond(4.0);

    std::cout << "First of pairTwo " << pairTwo.getFirst() << " and Second of pairTwo " << pairTwo.getFirst() << std::endl;

    pairTwo + 1.0;
    std::cout << pairTwo;

    return 0;
}
