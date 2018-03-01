#ifndef CHARACTER_H
#define CHARACTER_H

class Player;

class Character {
protected: //probs not here
    int atkpt;
    int defence;
    int HP;
    int row;
    int col;
    int gold;
    int max_HP;
public:
    //we need the atkpt, defense, HP, gold so I can initialize the fields of characters with constants in the derived classes.
    //Character(int atkpt, int defence, int HP, Character*character, int gold); /**/
    Character(int atkpt, int defence, int HP, int row, int col, int gold);
    virtual char getType() = 0; 
	virtual char canPrintType() = 0;
	virtual Player* addPotion(Player * player);
	virtual Player* addGold(Player * p);
    virtual int defend(Character *attacker) = 0;
    virtual bool attack(Character *defender) = 0; 
	virtual void attackThief(Player * p);
    virtual bool isSlain();
	virtual bool isAvailable();
    virtual int getHP();
    virtual int getatk();
    virtual int getDef();
	virtual int getGold();
	virtual int getOriHP();
	virtual int getOriatk();
	virtual int getOriDef();
	virtual void move(int relativeX, int relativeY);
    virtual ~Character();
	int getX();
	int getY();
};


#endif
