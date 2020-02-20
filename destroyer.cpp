// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#include "destroyer.h"
using namespace std;

/********** Destroyer Class **********/

// Default Constructor
Destroyer::Destroyer(Battleship boat) : Battleship(boat) {
}

// Alternate Constructor
Destroyer::Destroyer(string pName) : Battleship(pName) {
}

// Full Constructor
Destroyer::Destroyer(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed) : Battleship(pName, pMaxHitPoints, pFirePower, pAccuracy, pSpeed) {
}

// Torpedoes Getter
Torpedoes Destroyer::getTorpedoes() const {
    return fTorpedoes;
}

// Torpedoes Setter
void Destroyer::setTorpedoes(int pFirePower, int pSpeed, int pRange) {
    fTorpedoes = Torpedoes(pFirePower, pSpeed, pRange);
}
