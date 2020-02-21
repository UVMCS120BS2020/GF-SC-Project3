// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#ifndef GF_SC_PROJECT3_TORPEDOES_H
#define GF_SC_PROJECT3_TORPEDOES_H

/********** Torpedoes Class **********/

class Torpedoes {
public:
    // Default Constructor
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Initializes Torpedoes object
    Torpedoes();

    // Full Constructor
    // Requires: Three ints for firepower, speed, and range
    // Modifies: Nothing
    // Effects: Initializes Torpedoes object
    Torpedoes(int pFirePower, int pSpeed, int pRange);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns Torpedoes field
    int getFirePower() const;
    int getSpeed() const;
    int getRange() const;

    // Setters
    // Requires: Int parameter
    // Modifies: Torpedoes field
    // Effects: Sets Torpedoes field to new parameter
    void setFirePower(int pFirePower);
    void setSpeed(int pSpeed);
    void setRange(int pRange);

private:
    // Fields
    int fFirePower = 50000;
    int fSpeed = 15;
    int fRange = 15;
};

#endif //GF_SC_PROJECT3_TORPEDOES_H
