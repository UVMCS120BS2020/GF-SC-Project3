//
// Created by Sean Cosgrove on 2/20/2020.
//

#ifndef GF_SC_PROJECT3_DESTROYER_H
#define GF_SC_PROJECT3_DESTROYER_H

#include "battleship.h"
#include "torpedoes.h"

/********** Destroyer Class **********/

class Destroyer : public Battleship {
protected:
    Torpedoes fTorpedoes;
public:
    // Constructors
    explicit Destroyer(Battleship boat);
    explicit Destroyer(string pName);
    Destroyer(string pName, int pMaxHitPoints, int pFirePower, int pAccuracy, int pSpeed);

    // Getters
    Torpedoes getTorpedoes() const;

    // Setters
    void setTorpedoes(int pFirePower, int pSpeed, int pRange);
};

#endif //GF_SC_PROJECT3_DESTROYER_H
