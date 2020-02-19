//
// Created by George on 2/07/20
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

// MAIN
int main(){

    Battleship userShip = makeUserBattleship();
    int userX;
    int userY;
    int counter = 0;
    char choice;
    while (userShip.getDestroyed() == false){
        cout << "Enter your X position: ";
        cin >> userX;
        userShip.setX(userX);
        cout << "Enter your Y position: ";
        cin >> userY;
        userShip.setY(userY);
        cout << "Battle enemy ship? (Y/N) ";
        cin >> choice;
        if (choice != 'Y' || choice != 'y' ){
            ++counter;
            unique_ptr<Battleship> computerPtr = make_unique<Battleship>("Computer " + to_string(counter));
            computerPtr->setX(0);
            computerPtr->setY(0);
            cout << "Your distance from " << computerPtr->getName() << " is " << calcDistance(userShip, *computerPtr) << endl;
            battle(userShip, *computerPtr);
        } else if(choice == 'n' || choice != 'N') {
            cout << "you're a wimp" << endl;
        } else {
            cout << "thats not a y or an n" << endl;
        }
    }
    cout << "You were destroyed. Game Over." << endl;

    return 0;
}

// Global function definitions
Battleship makeUserBattleship(){
    string name;
    int hitPoints;
    int firePower;
    int accuracy;
    int speed;
    cout << "Enter the name of your Battleship: ";
    getline(cin, name);
    cout << "Enter the Hitpoints of your Battleship (Integer Between 100-30,000): ";
    cin >> hitPoints;
    if (hitPoints < 100 || hitPoints > 30000) {
        cout << "Invalid hit points, set to default (1,000)" << endl;
        hitPoints = 1000;
    }
    cout << "Enter the Fire Power of your Battleship (Between 50,000-1,000,000): ";
    cin >> firePower;
    if (firePower < 50000 || firePower > 1000000) {
        cout << "Invalid fire power, set to default (50,000)" << endl;
        firePower = 50000;
    }
    cout << "Enter the Accuracy of your Battleship (Between 1-100): ";
    cin >> accuracy;
    if (accuracy < 0 || accuracy > 100) {
        cout << "Invalid pAccuracy, set to default (75)" << endl;
        accuracy = 75;
    }
    cout << "Enter the Speed of your Battleship (Between 1-100): ";
    cin >> speed;
    if (speed < 0 || speed > 100){
        cout << "Invalid pSpeed, set to default (50)" << endl;
        speed = 50;
    }
    unique_ptr<Battleship> userShip = make_unique<Battleship>(name, hitPoints, firePower, accuracy, speed);
    return *userShip;
}

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