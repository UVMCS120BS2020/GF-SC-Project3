//
// Created by Sean Cosgrove on 2/20/2020.
//

#include "destroyer.h"
using namespace std;

/********** Destroyer Class **********/

// Constructors
Destroyer::Destroyer(Battleship boat) : Battleship(boat) {
}
Destroyer::Destroyer(string pName) : Battleship(pName) {
}
Destroyer::Destroyer(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed) : Battleship(pName, pMaxHitPoints, pFirePower, pAccuracy, pSpeed) {
}
