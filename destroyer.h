//
// Created by Sean Cosgrove on 2/20/2020.
//

#ifndef GF_SC_PROJECT3_DESTROYER_H
#define GF_SC_PROJECT3_DESTROYER_H

#include "battleship.h"

/********** Destroyer Class **********/

class Destroyer : public Battleship {
public:
    /* Constructors */
    explicit Destroyer(Battleship boat);
    Destroyer(string pName);
    Destroyer(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed);
};

#endif //GF_SC_PROJECT3_DESTROYER_H
