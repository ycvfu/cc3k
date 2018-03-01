#include "floor.h"
#include "position.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <algorithm>
#include "../Pieces/Characters/Players/shade.h"
#include "../Pieces/Characters/Players/troll.h"
#include "../Pieces/Characters/Players/drow.h"
#include "../Pieces/Characters/Players/goblin.h"
#include "../Pieces/Characters/Players/vampire.h"

#include "../Pieces/Characters/Enemies/enemy.h"
#include "../Pieces/Characters/Enemies/dragon.h"
#include "../Pieces/Characters/Enemies/dwarf.h"
#include "../Pieces/Characters/Enemies/elf.h"
#include "../Pieces/Characters/Enemies/halfling.h"
#include "../Pieces/Characters/Enemies/human.h"
#include "../Pieces/Characters/Enemies/merchant.h"
#include "../Pieces/Characters/Enemies/orc.h"

#include "../Potions/restoreHealth.h"
#include "../Potions/boostAttack.h"
#include "../Potions/boostDefence.h"
#include "../Potions/poisonHealth.h"
#include "../Potions/woundAttack.h"
#include "../Potions/woundDefence.h"

#include "../Treasures/dragonHoard.h"
#include "../Treasures/merchantHoard.h"
#include "../Treasures/normalGold.h"
#include "../Treasures/smallGold.h"

using namespace std;

Floor::Floor() : floorNum{1}, player{nullptr}, isWon{false} {
   theFloor.assign(height, vector<Tile>(width, Tile()));
   textdisplay = new TextDisplay(width, height);
   readMap(); //initialized floor from map
   createChambers();
}

Floor::~Floor() {
   delete textdisplay;
}

void Floor::nextFloor() {
	std::cout << "Congratulations on passing Floor " << floorNum - 1 << "!!" << std::endl;
	if (floorNum == 5) isWon = true; return;
	std::cout << "Welcome to Floor " << floorNum << ", young warrior!" << std::endl;
	Player * next;
	if (player->getType() == 'R') {
		next = new Drow{player};
	} else if (player->getType() == 'G') {
		next = new Goblin{player};
	} else if (player->getType() == 'S') {
		next = new Shade{player};
	} else if (player->getType() == 'T') {
		next = new Troll{player};
	} else {
		next = new Vampire{player};
	}
	theFloor.assign(height, vector<Tile>(width, Tile()));
	player = next;
	delete textdisplay;
	textdisplay = new TextDisplay(width, height);
	readMap();
	createChambers();
	Position place = randomizeTile();
	int oldX = player->getX();
	int oldY = player->getY();
	player->move(place.row - oldX, place.col - oldY);

	theFloor[player->getX()][player->getY()].addPiece(player);
	spawnPieces();
}



void Floor::spawnPlayer(char type){
   Position randTile = randomizeTile();
   int row = randTile.row;
   int col = randTile.col;
   
   switch(type) {
      case 's': player = new Shade(row, col); break;
	  case 't': player = new Troll(row, col); break;
	  case 'g': player = new Goblin{row, col}; break;
	  case 'd': player = new Drow(row, col); break;
	  case 'v': player = new Vampire(row, col); break;
   }

   theFloor[row][col].addPiece(player);
   this->player = player;
}

void Floor::spawnPieces() {
   spawnStairs();
   spawnPotions();
   spawnTreasures();
   spawnEnemies();
 }

// //note: path might not work, need to test
// void Floor::readPieces(string filename) {
//   //read pieces from file 
//   ifstream ifsmap{filename};
//   string line;
//   char pieceType;
//   Piece *piece;


//   //initialize Tiles 
//   for (int r = 0; r < height; r++) {
//     getline(ifsmap, line);
//     for (int c = 0; c < width; c++) {
//       switch(line[c]) {
//         //TODO: check these are right 
//         case '@': piece = new Shade(r, c); break;
//         case 'H': piece = new Human(r, c); break;
//         case 'W': piece = new Dwarf(r, c); break;
//         case 'E': piece = new Elf(r, c); break;

//         case 'O': piece = new Orc(r, c); break;
//         case 'M': piece = new Merchant(r, c); break;
//         case 'D': piece = new Dragon(r, c); break;
//         casek-check=full 'L': piece = new Halfling(r, c); break;
//         case '0': piece = new RestoreHealth(r, c); break;
//         case '1': piece = new BoostAttack(r, c); break;
//         case '2': --leak-check=fullpiece = new BoostDefence(r, c); break;
//         case '3': piece = new PoisonHealth(r, c); break;
//         case '4': piece = new WoundAttack(r, c); break;
//         case '5': piece = new WoundDefence(r, c); break;
//         case '6': piece = new NormalGold(r, c); break;
// //note: path might not work, need to test
// void Floor::readPieces(string filename) {
//   //read pieces from file 
//   ifstream ifsmap{filename};
//   string line;
//   char pieceType;
//   Piece *piece;


//   //initialize Tiles 
//   for (int r = 0; r < height; r++) {
//     getline(ifsmap, line);
//     for (int c = 0; c < width; c++) {
//       switch(line[c]) {
//         //TODO: check these are right 
//         case '@': piece = new Shade(r, c); break;
//         case 'H': piece = new Human(r, c); break;
//         case 'W': piece = new Dwarf(r, c); break;
//         case 'E': piece = new Elf(r, c); break;

//         case 'O': piece = new Orc(r, c); break;
//         case 'M': piece = new Merchant(r, c); break;
//         case 'D': piece = new Dragon(r, c); break;
//         casek-check=full 'L': piece = new Halfling(r, c); break;
//         case '0': piece = new RestoreHealth(r, c); break;
//         case '1': piece = new BoostAttack(r, c); break;
//         case '2': --leak-check=fullpiece = new BoostDefence(r, c); break;
//         case '3': piece = new PoisonHealth(r, c); break;
//         case '4': piece = new WoundAttack(r, c); break;
//         case '5': piece = new WoundDefence(r, c); break;
//         case '6': piece = new NormalGold(r, c); break;
//         case '7': piece = new SmallHoard(r, c); break;
//         case '8': piece = new MerchantHoard(r, c); break;
//         case '9': piece = new DragonHoard(r, c); break;
//         default: piece = nullptr;
//       }
//       if (piece) { theFloor[r][c].addPiece(piece); }
//     }
//   }
// }

void Floor::moveEnemies() {
	
	for (int i=0; i<20; i++) {
	    if (enemies[i]==nullptr) { continue; }
	    if (enemies[i]->isSlain()) {
		delete enemies[i];
		enemies[i] = nullptr;
		continue;
	    }
	    if (isEnemySurrounded(enemies[i])) { continue; }

	    if (playerIsClose(enemies[i])) {
		enemies[i]->attack(player);
		if (player->isSlain()) { return; }
		continue;
	    } 

	    Direction rDir = randomizeDir();
	    while (theFloor[enemies[i]->getY() + rDir.relativeY][enemies[i]->getX() + rDir.relativeX].isEnemyBlocked()) {
		rDir = randomizeDir();
	    }
            move(enemies[i], rDir);
}
}

bool Floor::playerIsClose(Enemy* enemy) {
	for (auto it = compass.begin(); it != compass.end(); ++it) {
		int r = enemy->getY() + it->second.relativeY;
		int c = enemy->getX() + it->second.relativeX;
		if (theFloor[r][c].getPiece() == player) {
			return true;
		}
	}
	return false;
}

void Floor::move(Character* character, Direction dir) {
	int newRow = character->getY() + dir.relativeY;
	int newCol = character->getX() + dir.relativeX;
	theFloor[newRow][newCol].addPiece(character);
	theFloor[character->getY()][character->getX()].removePiece();
	character->move(dir.relativeX, dir.relativeY);
}

Direction Floor::randomizeDir() {
	auto it = compass.begin();
	advance(it, rand() % 8);

	return it->second;
}

bool Floor::isEnemySurrounded(Enemy *enemy) {
	for (auto it = compass.begin(); it != compass.end(); ++it) {
		int r = enemy->getY() + it->second.relativeY;
		int c = enemy->getX() + it->second.relativeX;
		if (!theFloor[r][c].isBlockingEnemy()) {
			return false;
		}
	}
	return true;
}

 void Floor::movePlayer(Direction dir) {
    int row = player->getY() + dir.relativeY;
    int col = player->getX() + dir.relativeX;
	cout << theFloor[row][col].getType() << endl;
    if(theFloor[row][col].getType() == '/') {
			++floorNum;
			nextFloor();
    } else if(theFloor[row][col].getType() == 'G') {
			//decorate the player with the gold if it's available
	if ((theFloor[row][col].getPiece())->isAvailable()) {
		theFloor[player->getY()][player->getX()].removePiece();
        	 player = theFloor[row][col].getPiece()->addGold(player);
       		theFloor[row][col].addPiece(player);
	} else {
			// hit dragon hoard with alive dragon
			theFloor[row][col].getPiece()->attackThief(player);
		}
  } else if(theFloor[row][col].isWalkable() && !theFloor[row][col].getPiece()) {
       theFloor[row][col].addPiece(player);
       theFloor[player->getY()][player->getX()].removePiece();
       player->move(dir.relativeX, dir.relativeY);
    }
 }

bool Floor::isPlayerDead() {
     return player->isSlain(); 
}

void Floor::readMap() {
  //read map from file 
  ifstream ifsmap{mapfile};
  string line;
  char tileType;

  //initialize Tiles 
  for (int r = 0; r < height; r++) {
    getline(ifsmap, line);
    for (int c = 0; c < width; c++) {
      //add display as observer for each cell
      theFloor[r][c].attach(textdisplay);
      theFloor[r][c].setCoords(r, c); 
      theFloor[r][c].setType(line[c]);
    }
  }

}

void Floor::createChambers() {
  //read chamber positions from file 
  ifstream ifsmap{chambersfile};
  string line;
  char tileType;

  //add tiles to appropriate chamber 
  for (int r = 0; r < height; r++) {
    getline(ifsmap, line);
    for (int c = 0; c < width; c++) {
      if (isdigit(line[c])) { 
	    Position p{r,c};
	  	switch(line[c]) {
			cout << "ch num " << line[c] << " row " << r << " col " << c << endl;			
			case '0': Chamber1.emplace_back(p);break;
			case '1': Chamber2.emplace_back(p);break;
			case '2': Chamber3.emplace_back(p);break;
			case '3': Chamber4.emplace_back(p);break;
			case '4': Chamber5.emplace_back(p);break;
			cout << "after" << endl;
			}
		}
      }
    }
  }



Position Floor::randomizeTile() {
   int chamberNum = rand() % 5;
   int tileNum;
   Position t;
   switch(chamberNum) {
	case 0: 
		tileNum = rand() % Chamber1.size();
		t = Chamber1[tileNum];
		break;
	case 1: 
		tileNum = rand() % Chamber2.size();
		t = Chamber2[tileNum];
		break;
	case 2: 
		tileNum = rand() % Chamber3.size();
		t = Chamber3[tileNum];
		break;
	case 3: 
		tileNum = rand() % Chamber4.size();
		t = Chamber4[tileNum];
		break;
	case 4:
		tileNum = rand() % Chamber5.size();
		t = Chamber5[tileNum];
		break;
   }
   
   //find an unoccipied, non-stair tile
   while (theFloor[t.row][t.col].getPiece() != nullptr || theFloor[t.row][t.col].getType() == '/') {
       t = randomizeTile();
   }

   return t;
}

void Floor::spawnStairs() {
    Position t = randomizeTile();
    theFloor[t.row][t.col].setType('/');
}

void Floor::spawnPotions() {
	int potionType;
	Position t;
	Potion *potion;

	//create 10 potions 
	for (int i = 0; i < 10; i++) {
		t = randomizeTile();
		potionType = rand() % 6;
		switch (potionType) {
			case 0: potion = new RestoreHealth(t.row, t.col); break;
			case 1: potion = new BoostAttack(t.row, t.col); break;
			case 2: potion = new BoostDefence(t.row, t.col); break;
			case 3: potion = new PoisonHealth(t.row, t.col); break;
			case 4: potion = new WoundAttack(t.row, t.col); break;
			case 5: potion = new WoundDefence(t.row, t.col); break;
		}
		theFloor[t.row][t.col].addPiece(potion);
	}
}

void Floor::spawnTreasures() {
	int treasureType;
	Treasure *treasure;
	Position t;

	//create 10 treasures
	for (int i = 0; i < 10; i++) {
		t = randomizeTile();
		treasureType = rand() % 8;
		bool dragon = false;
		switch (treasureType) {
			case 0: case 1:
				treasure = new SmallGold(t.row, t.col); break;
			case 2: case 3: case 4: case 5: case 6:
				treasure = new NormalGold(t.row, t.col); break;
			case 7:
				treasure = new DragonHoard(t.row, t.col); dragon = true; break;
		}
		theFloor[t.row][t.col].addPiece(treasure);

		// creates + assigns dragon
		while (dragon) {
			const int dX = rand() % 3;
			const int dY = rand() % 3;
			if (theFloor[t.row + dX - 1][t.col + dY - 1].isWalkable() && theFloor[t.row + dX - 1][t.col + dY - 1].getPiece() == nullptr) {
				Dragon * guard = new Dragon{t.row + dX - 1, t.col + dY - 1, treasure};
				theFloor[t.row + dX - 1][t.col + dY - 1].addPiece(guard);
				treasure->assignGuard(guard);
				break;
			}
		}
	}
}



void Floor::spawnEnemies() {
   int enemyType;
   Enemy *enemy;
   Position t;

   //create 20 enemies 
   for (int i = 0; i < 20; i++) {
     t = randomizeTile();
     enemyType = rand() % 18;
     switch (enemyType) {
       case 0: case 1: case 2: case 3:
         enemy = new Human(t.row, t.col); break;
       case 4: case 5: case 6:
         enemy = new Dwarf(t.row, t.col); break;
       case 7: case 8: case 9: case 10: case 11:
         enemy = new Halfling(t.row, t.col); break;
       case 12: case 13:
         enemy = new Elf(t.row, t.col); break;
       case 14: case 15:
         enemy = new Orc(t.row, t.col); break;
       case 16: case 17:
         enemy = new Merchant(t.row, t.col); break;
     }
     theFloor[t.row][t.col].addPiece(enemy);
	 enemies.emplace_back(enemy);
   }
 }

map<string, Direction> Floor::compass = {
	{"no", {0, -1}},
	{"so", {0, 1}},
	{"ea", {1, 0}},
	{"we", {-1, 0}},
	{"ne", {1, -1}},
	{"nw", {-1, -1}},
	{"se", {1, 1}},
	{"sw", {-1, 1}}
};

int Floor::getFloorNum() const {
	return floorNum;
}

ostream &operator<<(std::ostream &out, const Floor &f) {
   string c;
   if(f.player->getType() == 'S') {
     c = "Shade";
    } else if(f.player->getType() == 'R') {
     c = "Drow";
    } else if(f.player->getType() == 'V') {
     c = "Vampire";
    } else if(f.player->getType() == 'T') {
     c = "Troll";
    } else {
     c = "Goblin";
    }

   out << *(f.textdisplay);
   out << endl;
   out << "Race: " << c << " Gold: " << f.player->getGold() <<"\t\t\t\t\t\tFloor: " << f.getFloorNum() <<endl;
   out << "HP: " << f.player->getHP() << endl;
   out << "Atk: " << f.player->getatk() << endl;
   out << "Def: " << f.player->getDef() << endl;
   out << "Action: "; 

   return out;
}

void Floor::playerAttack(Direction dir) {
	int row = player->getY() + dir.relativeY;
	int col = player->getX() + dir.relativeX;
	if(theFloor[row][col].getPiece() && theFloor[row][col].getPiece()->getType() == 'E') {
		player->attack(theFloor[row][col].getPiece());
		if(theFloor[row][col].getPiece()->isSlain()) {
                        char c = theFloor[row][col].getPiece()->canPrintType();
			//delete theFloor[row][col].getPiece();
			theFloor[row][col].removePiece();
                        if(theFloor[row][col].getPiece() == nullptr) cout << "wowww null" << endl;
                        if(c == 'M') {
                          cout << "HEY" <<endl;
                          Treasure *t = new MerchantHoard(col, row);
                          cout << "HEYY" <<endl;
                          theFloor[row][col].addPiece(t);
                          cout << "HEY!" << endl;
                        } else if( c == 'H') {
                          Treasure *t = new NormalGold(col, row);
                          Treasure *t1 = new NormalGold(col, row); 
                          theFloor[row][col].addPiece(t);
                          int r = row;
                          int c = col;
                          if(!theFloor[row + 1][col].isBlocked()) {
                               r = row + 1;
                           } else if(!theFloor[row - 1][col].isBlocked()) {
                               r = row - 1;
                           } else if(!theFloor[row][col + 1].isBlocked()) {
                              c = col + 1;
                           } else if(!theFloor[row][col - 1].isBlocked()) {
                              c = col - 1;
                           } else if(!theFloor[row + 1][col - 1].isBlocked()) {
                              r = row + 1;
                              c = col - 1;
                           } else if(!theFloor[row + 1][col + 1].isBlocked()) {
                              r = row + 1;
                              c = col + 1;
                           } else if(!theFloor[row - 1][col - 1].isBlocked()) {
                              r = row - 1;
                              c = col - 1;
                           } else if(!theFloor[row - 1][col + 1].isBlocked()) {
                              r = row - 1;
                              c = col + 1;
                           }
                           cout << "PARKING SPOT HERE" << endl;
                           theFloor[r][c].addPiece(t1);
		}
	}
}
}

void Floor::potionUse(Direction dir) {
   int row = player->getY() + dir.relativeY;
        int col = player->getX() + dir.relativeX;
	if(theFloor[row][col].getPiece()) {
        if(theFloor[row][col].getType() == 'P') {
        theFloor[player->getY()][player->getX()].removePiece();
        player = theFloor[row][col].getPiece()->addPotion(player);
        theFloor[player->getY()][player->getX()].addPiece(player);
         }
}
}

bool Floor::isWinner() {
    return isWon;
}
