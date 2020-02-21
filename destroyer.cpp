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

// Fire method
// Requires: target Battleship object
// Modifies: the currentHitPoints of the second battleship object.
// Effects: lowers the HP of the second battleship, checks if it is destroyed.
void Destroyer::fire(Destroyer &pReceiving) {
    // damage divides the firepower by (firing Battleship's Accuracy (100 being the most accurate) - pReceiving Battleship's Speed
    // (100 being the fastest). (named factors, negative factors will be treated as 0. A factor of 100 will be treated as 99.)
    // final calculation is done as 101 - factors to properly apply the effects. (lower the factors score, less damage)
    if (this->getDestroyed() == false){
        Torpedoes missile = this->getTorpedoes();
        int missileDamage = missile.getFirePower();
        int missileSpeed = missile.getSpeed();
        int missileRange = missile.getRange();
        int factors = this->getAccuracy() - (this->getSpeed() + missileSpeed);
        if (factors < 0) {
            factors = 0;
        }
        int damage = (this->getFirePower() + missileDamage) / (101 - factors);
        int health = pReceiving.getCurrentHitPoints();
        if (damage > health) {
            pReceiving.setCurrentHitPoints(0);
            pReceiving.setDestroyed(true);
            cout << pReceiving.getName() << " was destroyed by a shot from " << this->getName() << "." << endl;
        } else {
            pReceiving.setCurrentHitPoints(health - damage);
            cout << pReceiving.getName() << " took " << damage << " damage from " << this->getName() << "." << endl;
            cout << pReceiving.getName() << " now has " << pReceiving.getCurrentHitPoints() << " hit points." << endl;
        }
    } else {
        cout << this->getName() << " cannot fire, it is destroyed." << endl;
    }
}
