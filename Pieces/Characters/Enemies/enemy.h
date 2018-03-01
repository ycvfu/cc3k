#ifndef ENEMY_H
#define ENEMY_H
#include "../character.h"

class Enemy : public Character{
public:
//how does inheriting twice work? 
     Enemy(int atkpt, int defence, int HP, int row, int col, int gold);
    virtual ~Enemy();
    //I can't deal with treausure. 
    virtual int defend(Character *attacker) override;
    virtual bool attack(Character *defender) override;
    char getType() override;
    virtual char canPrintType() = 0;
};


#endif



