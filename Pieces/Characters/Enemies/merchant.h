#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"
class Merchant: public Enemy {
    static bool Hostile;
    // since static fields can only be accessed by static methods
    // how about creating a (private) static method to change that static field
    public:
    Merchant(int row, int col);
    bool attack(Character *defender) override;
    int defend(Character *attacker) override;
    bool isHostile();
    char canPrintType() override;
};
#endif
