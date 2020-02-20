// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#ifndef GF_SC_PROJECT3_BATTLESHIP_H
#define GF_SC_PROJECT3_BATTLESHIP_H
#include <string>
#include <iostream>
#include <optional>
#include <memory>
using namespace std;

typedef optional<int> OptInt;

class Battleship{
public:
    // Default constructor
    // Requires: String Name
    // Modifies: fHitPoints, fFirePower, fAccuracy, fSpeed, fName
    // Effects: Sets the fields to default values, and sets the Name
    Battleship(string pName);

    // Full Constructor
    // Requires: string name, int pMaxHitPoints range: (100-30,000) , int fire Power range: (50,000-1,000,000), int pAccuracy range: (1-100), int pSpeed range: (1-100)
    // Modifies: sets the fields to the specified values, if an incorrect value is entered it will use the default value.
    // Effects: creates a battleship object with the specified values
    Battleship(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed);

    // Getters
    // requires: Nothing
    // Modifies: nothing
    // effects: returns the requested value
    int getMaxHitPoints() const;
    int getFirePower() const;
    int getAccuracy() const;
    int getSpeed() const;
    int getCurrentHitPoints() const;
    int getRange() const;
    string getName() const;
    bool getDestroyed() const;
    OptInt getX() const;
    OptInt getY() const;

    // Setters
    // Requires: value to set to (must be valid see Constructor specifications)
    // Modifies: modifies the field and sets it to the new value
    // Effects: changes the field values
    void setMaxHitPoints(int pMaxHitPoints);
    void setFirePower(int pFirePower);
    void setCurrentHitPoints(int currentHitPoints);
    void setSpeed(int pSpeed);
    void setName(string pName);
    void setAccuracy(int pAccuracy);
    void setDestroyed(bool pStatus);
    void setRange(int pRange);
    void setX(int pX);
    void setY(int pY);
    void setXNull();
    void setYNull();

    // Fire method
    // Requires: Receiving battleship object
    // Modifies: the currentHitPoints of the receiving battleship object.
    // Effects: lowers the HP of the receiving battleship, checks if it is destroyed.
    void fire(Battleship &pReceiving);



private:
    // fields
    string fName;
    int fMaxHitPoints;
    int fCurrentHitPoints;
    int fFirePower;
    int fSpeed;
    int fAccuracy;
    bool fDestroyed;
    OptInt fX;
    OptInt fY;

};


#endif //GF_SC_PROJECT3_BATTLESHIP_H
