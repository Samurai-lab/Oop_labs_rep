#include <iostream>
#include "ship.h"

ship::ship() {
    this->name = "default";
    this->displacement = 0;
    this->shipType = "default";
    std::cout << "Default constructor did work: " << "ship name is " << name
              << ", displacement is " << displacement
              << " and ship type is " << shipType << std::endl;
}

ship::ship(char *newName, int newDisplacement, char *newShipType) : name(newName),
                                                                    displacement(newDisplacement),
                                                                    shipType(newShipType) {
    std::cout << "Parameters constructor did work: " << "ship name is " << name
              << ", displacement is " << displacement
              << " and ship type is " << shipType << std::endl;
}

ship::ship(const ship &otherShip) {
    this->name = otherShip.name;
    this->displacement = otherShip.displacement;
    this->shipType = otherShip.shipType;

    std::cout << "Copy constructor did work: " << "ship name is " << name
              << ", displacement is " << displacement
              << " and ship type is " << shipType << std::endl;

}

ship::~ship() {
    std::cout << "Destructor did work: " << "ship name is " << name
              << ", displacement is " << displacement
              << " and ship type is " << shipType << std::endl;

}

void ship::setName(char *newName) {
    this->name = newName;
}

void ship::setDisplacement(int newDisplacement) {
    this->displacement = newDisplacement;
}

void ship::setShipType(char *newShipType) {
    this->shipType = newShipType;
}

void ship::setAll(char *newName, int newDisplacement, char *newShipType) {
    this->name = newName;
    this->displacement = newDisplacement;
    this->shipType = newShipType;
}

char *ship::getName() {
    return this->name;
}

int ship::getDisplacement() const {
    return this->displacement;
}

char *ship::getShipType() {
    return this->shipType;
}

void ship::displayInfo() {
    std::cout << "Ship name is " << this->name
              << ", displacement is " << this->displacement
              << " and ship type is " << this->shipType << std::endl;

}


