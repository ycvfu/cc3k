#ifndef ELF_H
#define ELF_H
#include "enemy.h"

class Elf : public Enemy {
	public:
    Elf(int row, int col);
    int defend(Character *attacker) override; 
    bool attack(Character * defender) override; 
	char canPrintType() override;
	virtual ~Elf();
};

#endif
    
