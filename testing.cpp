//
// Created by George on 2/7/20.
//

#include <string>
#include <iostream>
#include <optional>
#include <memory>
#include <cmath>
#include "battleship.h"

using namespace std;

// Global functions declarations
// make user battleship
// Requires: nothing
// modifies: creates a new battleship with user input values
// effects: returns a new battleship
Battleship makeUserBattleship();

// Requires: two battleships
// modifies: hitpoints of the battleships
// effects: fires until one is destroyed (takes turns, battleship one goes first). returns the winner.
Battleship battle(Battleship &pOne, Battleship &pTwo);

// Distance calculator
// Requires: two battleship objects
// modifies: nothing
// effects: returns the integer division distance (straight line), or returns 0 if the coordinates do not exist
double calcDistance(Battleship pOne, Battleship pTwo);

// Tester functions
void testBattle();
void testCalcDistance();
// fire is a member of the Battleship class
// Fire requires: target ship
// fire modifies: hitpoints of target ship
// effects: lowers the HP of target ship if firing ship is not destroyed
void testFire();

int main(){
    testFire();
    testBattle();
    testCalcDistance();
    return 0;
};

void testFire(){
    Battleship one("One");
    Battleship two("Two");
    cout << "Testing the Fire function. Expected: Two took 657 damage from One.\\nTwo now has 343 hit points." << endl;
    cout << "Actual: ";
    one.fire(two);
}

void testBattle(){
    Battleship one("One");
    Battleship two("Two");
    cout << "Testing Battle function. Expected: Two is destroyed by a shot from One." << endl;
    cout << "Actual: ";
    battle(one, two);
    cout << "Testing Battle function. expected: cannot battle" << endl;
    battle(one, two);
    cout << "testing Battle function. expected: cannot battle" << endl;
    battle(two, one);
    Battleship three("Three");
    cout << "testing Battle function. Expected: one is destroyed by a shot from 3" << endl;
    battle(one, three);
}

void testCalcDistance(){
    Battleship one("One");
    Battleship two("Two");
    one.setX(3);
    one.setY(4);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (3, 4) Two: (0, 0) Expected: 5" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(0);
    one.setY(0);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (0, 0) Two: (0, 0) Expected: 0" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(1);
    one.setY(2);
    two.setX(1);
    two.setY(2);
    cout << "Testing calcDistance function. One: (1, 2) Two: (1, 2) Expected: 0" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(0);
    one.setY(0);
    two.setX(6);
    two.setY(8);
    cout << "Testing calcDistance function. One: (0, 0) Two: (6, 8) Expected: 10" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(-3);
    one.setY(-4);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (-3, -4) Two: (0, 0) Expected: 5" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(-3);
    one.setY(-4);
    two.setX(-8);
    two.setY(-6);
    cout << "Testing calcDistance function. One: (-3, -4) Two: (-8, -6) Expected: ~5" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setX(3);
    one.setY(4);
    two.setX(8);
    two.setY(6);
    cout << "Testing calcDistance function. One: (3, 4) Two: (8, 6) Expected: ~5" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
    one.setXNull();
    one.setYNull();
    two.setXNull();
    two.setYNull();
    cout << "Testing calcDistance function. X: null Y: null Expected: 0" << endl;
    cout << "actual: " << calcDistance(one, two) << endl;
}

// Global function definitions
Battleship battle(Battleship &pOne, Battleship &pTwo){
    if (pOne.getDestroyed() == false && pTwo.getDestroyed() == false) {
        while (pOne.getDestroyed() == false && pTwo.getDestroyed() == false) {
            pOne.fire(pTwo);
            if (pTwo.getDestroyed() == false) {
                pTwo.fire(pOne);
            }
        }
        if (pOne.getDestroyed() == false) {
            return pOne;
        } else {
            return pTwo;
        }
    } else{
        if (pOne.getDestroyed()){
            cout << "cannot battle, " << pOne.getName() << " is destroyed" << endl;
            return pTwo;
        } else{
            cout << "cannot battle, " << pTwo.getName() << " is destroyed" << endl;
            return pOne;
        }
    }
}


double calcDistance(Battleship pOne, Battleship pTwo) {
    if (pOne.getX() && pTwo.getX() && pOne.getY() && pTwo.getY()) {
        int xDifference;
        int yDifference;
        xDifference = (*pOne.getX() - *pTwo.getX());
        yDifference = (*pOne.getY() - *pTwo.getY());

        if (xDifference < 0) {
            xDifference = xDifference * -1;
        }
        if (yDifference < 0) {
            yDifference = yDifference * -1;
        }
        double totDistance = sqrt((xDifference * xDifference) + (yDifference * yDifference));
        return totDistance;
    } else {
        return 0.0;
    }
}