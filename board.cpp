//
// Created by George on 2/20/20.
//
#include "board.h"
#include <string>
#include <iostream>
#include <optional>
#include <memory>

Board::Board(){
    fSizeX = 1000;
    fSizeY = 1000;
}

// Getters
int Board::getSizeY(){
    return fSizeY;
}
int Board::getSizeX(){
    return fSizeX;
}

// Setters
void setSizeX(int pSize){
    fSizeX = pSize;
}
void setSizeY(int pSize){
    fSizeY = pSize;
}

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

void Board::moveX(Battleship pMoveMe, bool pForward) {
    if (pMoveMe.getX()){
        int speed = pMoveMe.getSpeed();
        int start = pMoveMe.getX();
        if (pForward){
            if (start + speed > this->fSizeX) {
                pMoveMe.setX(start + speed);
            } else{
                pMoveMe.setX(this->fSizeX);
            }
        } else{
            if (start - speed > 0) {
                pMoveMe.setX(start - speed);
            } else{
                pMoveMe.setX(0);
            }
        }
    } else{
        cout << "cannot move, no position assigned."
    }
}

void Board::moveY(Battleship pMoveMe, bool pForward) {
    if (pMoveMe.getY()){
        int speed = pMoveMe.getSpeed();
        int start = pMoveMe.getY();
        if (pForward){
            if (start + speed > this->fSizeY) {
                pMoveMe.setY(start + speed);
            } else{
                pMoveMe.setY(this->fSizeY);
            }
        } else{
            if (start - speed > 0) {
                pMoveMe.setY(start - speed);
            } else{
                pMoveMe.setY(0);
            }
        }
    } else{
        cout << "cannot move, no position assigned."
    }
}