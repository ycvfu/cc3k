#ifndef ORC_H
#define ORC_H
#include "enemy.h"

class Orc: public Enemy {
    public:
    Orc(int row, int col);
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;
    char canPrintType() override;
    virtual ~Orc();
};
#endif

