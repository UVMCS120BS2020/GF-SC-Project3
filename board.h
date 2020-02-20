//
// Created by George on 2/20/20.
//

#include <string>
#include <iostream>
#include <optional>
#include <memory>

using namespace std;
typedef optional<int> OptInt;

#ifndef GF_SC_PROJECT3_BOARD_H
#define GF_SC_PROJECT3_BOARD_H

class Board{
public:
    // Default constructor makes a board of default size, 1000 by 1000
    // Requires: nothing
    // Modifies: fSizeX and fSizeY
    // Effects: sets fSizeX and Y to 1000 each. Creates a new Board.
    Board();

    // Getters
    // Requires: nothing
    // Modifies: nothing
    // effects: returns the value
    int getSizeX() const;
    int getSizeY() const;

    // setters
    // requires: new value
    // modifies: the field requested
    // effects: sets the field to the new value
    void setSizeX(int pSize);
    void setSizeY(int pSize);

    // Distance calculator
    // Requires: two battleship objects
    // modifies: nothing
    // effects: returns the distance as a double (straight line), or returns 0 if the coordinates do not exist
    double calcDistance(Battleship pOne, Battleship pTwo);

    // movement functions
    // requires: battleship to move, and a true/false for forward/backwards
    // modifies: the X, Y of the battleship
    // effects: "moves" the battleship based on its speed and makes sure it is in bounds.
    void moveX(Battleship pMoveMe, bool pForward);
    void moveY(Battleship pMoveMe, bool pForward);
private:
    fSizeX;
    fSizeY;
};

#endif //GF_SC_PROJECT3_BOARD_H
