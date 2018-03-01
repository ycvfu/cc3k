#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human: public Enemy {
    public:
    Human(int row, int col);
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;
    //virtual std::bool dropGold() override;
    char canPrintType() override;
    virtual ~Human();
};


#endif
