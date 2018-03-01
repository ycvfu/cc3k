CXX = g++-5
CXXFLAGS = -std=c++14 -g -Werror -MMD
EXEC = cc3k
OBJECTS = main.o Floor/floor.o Floor/subject.o Floor/textdisplay.o Floor/tile.o Pieces/Characters/character.o Pieces/Characters/Players/drow.o Pieces/Characters/Players/goblin.o Pieces/Characters/Players/player.o Pieces/Characters/Players/shade.o Pieces/Characters/Players/troll.o Pieces/Characters/Players/vampire.o Potions/boostAttack.o Potions/boostDefence.o Potions/poisonHealth.o Potions/potion.o Potions/restoreHealth.o Potions/woundAttack.o Potions/woundDefence.o Treasures/dragonHoard.o Treasures/merchantHoard.o Treasures/normalGold.o Treasures/smallGold.o Treasures/treasure.o Pieces/Characters/Enemies/enemy.o Pieces/Characters/Enemies/dragon.o Pieces/Characters/Enemies/dwarf.o Pieces/Characters/Enemies/elf.o Pieces/Characters/Enemies/halfling.o Pieces/Characters/Enemies/human.o Pieces/Characters/Enemies/merchant.o Pieces/Characters/Enemies/orc.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
