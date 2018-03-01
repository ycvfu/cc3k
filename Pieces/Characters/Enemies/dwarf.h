#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"

class Dwarf: public Enemy {
    public:
    Dwarf(int row, int col);
    int defend(Character *attacker) override;
    //virtual std::bool dropGold() override;
    char canPrintType() override;
    bool attack(Character *defender) override;
};
#endif
