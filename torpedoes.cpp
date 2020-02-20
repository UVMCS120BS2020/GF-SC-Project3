// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#include "torpedoes.h"
using namespace std;

/********** Torpedoes Class **********/

// Default Constructor
Torpedoes::Torpedoes() {
}

// Full Constructor
Torpedoes::Torpedoes(int pFirePower, int pSpeed, int pRange) {
    fFirePower = pFirePower;
    fSpeed = pSpeed;
    fRange = pRange;
}

// Getters
int Torpedoes::getFirePower() const {
    return fFirePower;
}
int Torpedoes::getSpeed() const {
    return fSpeed;
}
int Torpedoes::getRange() const {
    return fRange;
}

// Setters
void Torpedoes::setFirePower(int pFirePower) {
    fFirePower = pFirePower;
}
void Torpedoes::setSpeed(int pSpeed) {
    fSpeed = pSpeed;
}
void Torpedoes::setRange(int pRange) {
    fRange = pRange;
}