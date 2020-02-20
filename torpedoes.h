//
// Created by Sean Cosgrove on 2/20/2020.
//

#ifndef GF_SC_PROJECT3_TORPEDOES_H
#define GF_SC_PROJECT3_TORPEDOES_H

/********** Torpedoes Class **********/

class Torpedoes {
public:
    // Constructors
    Torpedoes();
    Torpedoes(int pFirePower, int pSpeed, int pRange);

    // Getters
    int getFirePower() const;
    int getSpeed() const;
    int getRange() const;

    // Setters
    void setFirePower(int pFirePower);
    void setSpeed(int pSpeed);
    void setRange(int pRange);

private:
    // Fields
    int fFirePower;
    int fSpeed;
    int fRange;
};

#endif //GF_SC_PROJECT3_TORPEDOES_H
