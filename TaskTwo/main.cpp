#include <iostream>
#include "ship.h"

int main() {

    char *shipName = "Galka";
    int shipDisplacement = 500;
    char *shipType = "galeon";

    ship shipOne;

    ship shipTwo(shipName, shipDisplacement, shipType);

    ship shipThree(shipTwo);

    shipThree.setAll("Morocco", 700, "fregat");

    shipThree.displayInfo();

    ship buhta[3]{ship("First ship", 300, "kanonerka"),
                  ship("Second ship", 200, "kanonerka"),
                  ship("Third ship", 450, "fregat")};

    for (int i = 0; i < sizeof(buhta) / sizeof(ship); i++) {
        buhta[i].displayInfo();
    }

    void (ship::*show)();
    show = &ship::displayInfo;

    (shipThree.*show)();

    return 0;
}
