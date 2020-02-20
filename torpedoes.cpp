//
// Created by Sean Cosgrove on 2/20/2020.
//

#include "torpedoes.h"
using namespace std;

/********** Torpedoes Class **********/

// Constructors
Torpedoes::Torpedoes() {
}
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