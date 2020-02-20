// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#ifndef GF_SC_PROJECT3_DESTROYER_H
#define GF_SC_PROJECT3_DESTROYER_H

#include "battleship.h"
#include "torpedoes.h"

/********** Destroyer Class **********/

class Destroyer : public Battleship {
protected:
    Torpedoes fTorpedoes;
public:
    // Default Constructor
    // Requires: Battleship object
    // Modifies: Nothing
    // Effects: Initializes Destroyer object
    explicit Destroyer(Battleship boat);

    // Alternate Constructor
    // Requires: Name string
    // Modifies: Nothing
    // Effects: Initializes Destroyer object
    explicit Destroyer(string pName);

    // Full Constructor
    // Requires: Name string and four ints for max hit points, firepower, accuracy, and speed
    // Modifies: Nothing
    // Effects: Initializes Destroyer object
    Destroyer(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed);

    // Torpedoes Getter
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns Torpedoes field object
    Torpedoes getTorpedoes() const;

    // Torpedoes Setter
    // Requires: Three ints for firepower, speed, and range
    // Modifies: Torpedoes field
    // Effects: Sets Torpedoes field in Destroyer
    void setTorpedoes(int pFirePower, int pSpeed, int pRange);
};

#endif //GF_SC_PROJECT3_DESTROYER_H
