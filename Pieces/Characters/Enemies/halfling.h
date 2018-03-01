#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

//Please think long and hard before u change this code without my knowledge = - =
class Halfling: public Enemy {
    public:
    Halfling(int row, int col);
    virtual bool attack(Character *defender) override;
    virtual int defend(Character *attacker) override;
    //virtual std::bool dropGold() override;
    char canPrintType() override;
};
#endif
