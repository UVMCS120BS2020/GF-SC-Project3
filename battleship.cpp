//
// Created by George on 1/24/20
//

#include "battleship.h"
#include <string>
#include <iostream>
#include <optional>
#include <memory>
#include <cmath>

using namespace std;

typedef optional<int> OptInt;
// Default constructor
// Requires: String Name
// Modifies: fHitPoints, fFirePower, fAccuracy, fSpeed, fName
// Effects: Sets the fields to defualt values, and sets the Name
Battleship::Battleship(string pName){
    fName = pName;
    fMaxHitPoints = 1000;
    fCurrentHitPoints = 1000;
    fFirePower = 50000;
    fAccuracy = 75;
    fSpeed = 50;
    fDestroyed = false;
    fX = nullopt;
    fY = nullopt;
}

// Full Constructor
// Requires: string pName, int pMaxHitPoints range: (100-30,000) , int pFirePower range: (50,000-1,000,000), int pAccuracy range: (1-100), int pSpeed range: (1-100)
// Modifies: sets the fields to the specified values, if an incorrect value is entered it will use the default value.
// Effects: creates a battleship object with the specified values
Battleship::Battleship(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed){
    fName = pName;
    fMaxHitPoints = pMaxHitPoints;
    fCurrentHitPoints = pMaxHitPoints;
    fFirePower = pFirePower;
    fAccuracy = pAccuracy;
    fSpeed = pSpeed;
    fDestroyed = false;
    fX = nullopt;
    fY = nullopt;
}
// Getters
// requires: Nothing
// Modifies: nothing
// effects: returns the requested value

string Battleship::getName() const{
    return fName;
}
int Battleship::getFirePower() const{
    return fFirePower;
}
int Battleship::getMaxHitPoints() const{
    return fMaxHitPoints;
}
int Battleship::getCurrentHitPoints() const{
    return fCurrentHitPoints;
}
int Battleship::getSpeed() const{
    return fSpeed;
}
int Battleship::getAccuracy() const{
    return fAccuracy;
}
bool Battleship::getDestroyed() const{
    return fDestroyed;
}
OptInt Battleship::getX() const{
    return fX;
}
OptInt Battleship::getY() const{
    return fY;
}

// Setters
// Requires: value to set to (must be valid see Constructor specifications)
// Modifies: modifies the field and sets it to the new value
// Effects: changes the field values
void Battleship::setName(string pName){
    fName = pName;
}
void Battleship::setFirePower(int pFirePower){
    fFirePower = pFirePower;
}
void Battleship::setMaxHitPoints(int pMaxHitPoints){
    fMaxHitPoints = pMaxHitPoints;
}
void Battleship::setCurrentHitPoints(int newHitPoints){
    fCurrentHitPoints = newHitPoints;
}
void Battleship::setSpeed(int pSpeed){
    fSpeed = pSpeed;
}
void Battleship::setAccuracy(int pAccuracy){
    fAccuracy = pAccuracy;
}
void Battleship::setDestroyed(bool pStatus){
    fDestroyed = pStatus;
}
void Battleship::setX(int pX){
    this->fX = pX;
}
void Battleship::setXNull(){
    fX = nullopt;
}
void Battleship::setY(int pY){
    this->fY = pY;
}
void Battleship::setYNull(){
    fY = nullopt;
}

// Fire method
// Requires: target Battleship object
// Modifies: the currentHitPoints of the second battleship object.
// Effects: lowers the HP of the second battleship, checks if it is destroyed.
void Battleship::fire(Battleship &pReceiving){
    // damage divides the firepower by (firing Battleship's Accuracy (100 being the most accurate) - pReceiving Battleship's Speed
    // (100 being the fastest). (named factors, negative factors will be treated as 0. A factor of 100 will be treated as 99.)
    // final calculation is done as 101 - factors to properly apply the effects. (lower the factors score, less damage)
    if (this->getDestroyed() == false){
        int factors = this->getAccuracy() - this->getSpeed();
        if (factors < 0) {
            factors = 0;
        }
        int damage = this->getFirePower() / (101 - factors);
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



