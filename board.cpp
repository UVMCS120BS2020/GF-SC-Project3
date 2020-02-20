// George Fafard and Sean Cosgrove
// Lisa Dion
// CS 120
// Project 3: Battleship

#include "board.h"
#include <string>
#include <iostream>
#include <optional>
#include <memory>
#include <cmath>
#include <vector>

Board::Board(){
    fSizeX = 1000;
    fSizeY = 1000;
}

// Getters
int Board::getSizeY() const{
    return fSizeY;
}
int Board::getSizeX() const{
    return fSizeX;
}

// Setters
void Board::setSizeX(int pSize){
    fSizeX = pSize;
}
void Board::setSizeY(int pSize){
    fSizeY = pSize;
}

// TODO: they work, but implement to main
//void Board::addToBoard(Battleship pToAdd){
//    onBoard.push_back(pToAdd);
//}
//void Board::clearBoard(){
//    onBoard.clear();
//}

// calc distance function

double Board::calcDistance(Battleship pOne, Battleship pTwo) {
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

// movement functions

int Board::moveX(Battleship pMoveMe, bool pForward) {
    if (pMoveMe.getX()){
        int speed = pMoveMe.getSpeed();
        int start = *pMoveMe.getX();
        if (pForward){
            if (start + speed < fSizeX) {
                pMoveMe.setX(start + speed);
                return (start + speed);
            } else{
                pMoveMe.setX(fSizeX);
                return fSizeX;
            }
        } else{
            if (start - speed > 0) {
                pMoveMe.setX(start - speed);
                return (start - speed);
            } else{
                pMoveMe.setX(0);
                return 0;
            }
        }
    } else{
        cout << "cannot move, no position assigned.";
        return -1;
    }
}

int Board::moveY(Battleship pMoveMe, bool pForward) {
    if (pMoveMe.getY()){
        int speed = pMoveMe.getSpeed();
        int start = *pMoveMe.getY();
        if (pForward){
            if (start + speed < fSizeY) {
                pMoveMe.setY(start + speed);
                return start + speed;
            } else{
                pMoveMe.setY(fSizeY);
                return fSizeY;
            }
        } else{
            if (start - speed > 0) {
                pMoveMe.setY(start - speed);
                return start - speed;
            } else{
                pMoveMe.setY(0);
                return 0;
            }
        }
    } else{
        cout << "cannot move, no position assigned.";
        return -1;
    }
}