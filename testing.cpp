// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#include <string>
#include <iostream>
#include <optional>
#include <memory>
#include <cmath>
#include "battleship.h"
#include "destroyer.h"
#include "board.h"

using namespace std;

/********** Global functions declarations **********/

// battle
// Requires: two battleships
// Modifies: hitpoints of the battleships
// Effects: fires until one is destroyed (takes turns, battleship one goes first). returns the winner.
Battleship battle(Battleship &pOne, Battleship &pTwo);

// destroyer battle
// Requires: two destroyers
// Modifies: hitpoints of the destroyers
// Effects: fires until one is destroyed (takes turns, destroyer one goes first). returns the winner.
Destroyer destroyerBattle(Destroyer &pOne, Destroyer &pTwo);

// Tester functions
// test battle
// Requires: nothing
// Modifies: two Battleship objects
// Effects: calls battle function
void testBattle();

// test destroyer battle
// Requires: nothing
// Modifies: two Destroyer objects
// Effects: call destroyerBattle function
void testDestroyerBattle();

// test calc distance
// Requires: nothing
// Modifies: board and Battleship x and y coordinates
// Effects: tests movement around the board
void testCalcDistance();

// test fire, fire is a member of the Battleship class
// Requires: target ship
// Modifies: hitpoints of target ship
// Effects: lowers the HP of target ship if firing ship is not destroyed
void testFire();

// test destroyer fire, fire is overwritten in Destroyer class
// Requires: target ship
// Modifies: hitpoints of target ship
// Effects: lowers the HP of target ship if firing ship is not destroyed
void testDestroyerFire();

// test moveX and moveY (members of board)
// requires: a Battleship, a board, and a boolean fowrard
// modifies: the ships position
// effects: changes the ships position based on its speed
void testMoves();

// MAIN
int main(){
    testFire();
    testDestroyerFire();
    testBattle();
    testDestroyerBattle();
    testCalcDistance();
    testMoves();
    return 0;
};

/********** Global function definitions **********/

// testFire function
void testFire(){
    cout << "==========================================================================================================" << endl;
    Battleship one("One");
    Battleship two("Two");
    cout << "Testing the Fire function. Expected: Two took 657 damage from One; Two now has 343 hit points." << endl;
    cout << "Actual: ";
    one.fire(two);
}

// testDestroyerFire function
void testDestroyerFire() {
    cout << "==========================================================================================================" << endl;
    Destroyer one("One");
    Destroyer two("Two", 1100, 50000, 50, 50);
    cout << "Testing the Destroyer Fire function. Expected: Two took 1098 damage from One; Two now has 2 hit points." << endl;
    cout << "Actual: ";
    one.fire(two);
}

// testBattle function
void testBattle(){
    cout << "==========================================================================================================" << endl;
    Battleship one("One");
    Battleship two("Two");
    cout << "Testing Battle function. Expected: Two is destroyed by a shot from One." << endl;
    cout << "Actual: ";
    battle(one, two);
    cout << "Testing Battle function. expected: cannot battle" << endl;
    battle(one, two);
    cout << "Testing Battle function. expected: cannot battle" << endl;
    battle(two, one);
    Battleship three("Three");
    cout << "Testing Battle function. Expected: one is destroyed by a shot from 3" << endl;
    battle(one, three);
}

// testDestroyerBattle function
void testDestroyerBattle() {
    cout << "==========================================================================================================" << endl;
    Destroyer one("One");
    Destroyer two("Two");
    cout << "Testing Destroyer Battle function. Expected: Two is destroyed by a shot from One." << endl;
    cout << "Actual: ";
    destroyerBattle(one, two);
    cout << "Testing Destroyer Battle function. expected: cannot battle" << endl;
    destroyerBattle(one, two);
    cout << "Testing Destroyer Battle function. expected: cannot battle" << endl;
    destroyerBattle(two, one);
    Destroyer three("Three", 5000, 1000000, 100, 100);
    cout << "Testing Destroyer Battle function. Expected: One is destroyed by a shot from Three" << endl;
    destroyerBattle(one, three);
}

// battle function
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

// destroyerBattle function
Destroyer destroyerBattle(Destroyer &pOne, Destroyer &pTwo){
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

// testCalcDistance function
void testCalcDistance(){
    cout << "==========================================================================================================" << endl;
    Board board = Board();
    Battleship one("One");
    Battleship two("Two");
    one.setX(3);
    one.setY(4);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (3, 4) Two: (0, 0) Expected: 5" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(0);
    one.setY(0);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (0, 0) Two: (0, 0) Expected: 0" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(1);
    one.setY(2);
    two.setX(1);
    two.setY(2);
    cout << "Testing calcDistance function. One: (1, 2) Two: (1, 2) Expected: 0" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(0);
    one.setY(0);
    two.setX(6);
    two.setY(8);
    cout << "Testing calcDistance function. One: (0, 0) Two: (6, 8) Expected: 10" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(-3);
    one.setY(-4);
    two.setX(0);
    two.setY(0);
    cout << "Testing calcDistance function. One: (-3, -4) Two: (0, 0) Expected: 5" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(-3);
    one.setY(-4);
    two.setX(-8);
    two.setY(-6);
    cout << "Testing calcDistance function. One: (-3, -4) Two: (-8, -6) Expected: ~5" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setX(3);
    one.setY(4);
    two.setX(8);
    two.setY(6);
    cout << "Testing calcDistance function. One: (3, 4) Two: (8, 6) Expected: ~5" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
    one.setXNull();
    one.setYNull();
    two.setXNull();
    two.setYNull();
    cout << "Testing calcDistance function. X: null Y: null Expected: 0" << endl;
    cout << "actual: " << board.calcDistance(one, two) << endl;
}

// testMoves function
void testMoves(){
    cout << "==========================================================================================================" << endl;
    Battleship one = Battleship("One");
    Board board = Board();
    cout << "Setting One's initial position to 0, 0" << endl;
    one.setX(0);
    one.setY(0);
    cout << "Testing move forward X, should become 50. new Position: " << board.moveX(one, true) << endl;
    cout << "Testing move backward X, should become 0. new Position: " << board.moveX(one, false) << endl;
    cout << "Testing move Y, should become 50. new Position: " << board.moveY(one, true) << endl;
    cout << "Testing move down Y, should become 0. new Position: " << board.moveY(one, false) << endl;
    cout << "Testing no negative movements." << endl;
    cout << "Testing move down Y, should remain 0. new Position: " << board.moveY(one, false) << endl;
    cout << "Testing move backward X, should remain 0. new Position: " << board.moveX(one, false) << endl;
    one.setX(board.getSizeX());
    one.setY(board.getSizeY());
    cout << "Testing boundary movements." << endl;
    cout << "Moving out of bounds X, should stay 1000. new Position: " << board.moveX(one, true) << endl;
    cout << "Moving out of bounds Y, should stay 1000. new Position: " << board.moveY(one, true) << endl;
}