#ifndef TASKONE_SHIP_H
#define TASKONE_SHIP_H


class ship {
    char *name;
    int displacement;
    char *shipType;
public:
    ship();

    ship(char *name, int displacement, char *shipType);

    ship(const ship &otherShip);

    ~ship();

    void setName(char *newName);

    void setDisplacement(int newDisplacement);

    void setShipType(char *newShipType);

    void setAll(char *newName, int newDisplacement, char *newShipType);

    char *getName();

    int getDisplacement() const;

    char *getShipType();

    void displayInfo();


};


#endif
