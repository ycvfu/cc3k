#include "floor.h"
#include "position.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
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


//move enemy issue
//Fixed: I have two methods: move_enemy and move for all character: player will always return false for move_enemy, 
//   and enemies will always return true for move_enemy. Move will return false for player if fails. 

//figure out how to notify text display

Floor::Floor() : floorNum{1} {
   theFloor.assign(height, vector<Tile>(width, Tile()));
   textdisplay = new TextDisplay(width, height);
   readMap(); //initialized floor from map
   createChambers();
}

Floor::~Floor() {
   delete textdisplay;
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
//         case '7': piece = new SmallHoard(r, c); break;
//         case '8': piece = new MerchantHoard(r, c); break;
//         case '9': piece = new DragonHoard(r, c); break;
//         default: piece = nullptr;
//       }
//       if (piece) { theFloor[r][c].addPiece(piece); }
//     }
//   }
// }

// //the tile not the occupier.
// &Tile getTile(int row, int col) {
//     return theFloor[row][col]; 
// }

// //p for potions in getType()
// void usePotion(Direction dir) {
//     int x = player->getX() + dir.relativeX;
//     int y = player->getY() + dir.relativeY;
//     if(theFloor[x][y].getType() == 'p') {
//         //calling addPotion() on Potion. Passes the potion player pointer.
//         theFloor[x][y].getPiece()->--leak-check=fulladdPotion(player);
//     }--leak-check=full
// }

// void Floor::pause() {
//     if(paused) {
//         paused = false;
//     } else {
//         paused = true;
//     }
// }


// //This should be okay
// void Floor::moveEnemy(Direction dir) {
    

/*while(true) {
int x = i;
int y = j;
      int k  = rand()  % 2  ;
      k = k - 1;
      int k2 = rand() % 2;
      k2 = k2 -1;
      x = x + k;
      y = y + k;

      if(theFloor[x][y].isWalkable() && !theFloor[x][y].getPiece()) {



     if((j+1 <= width) && theFloor[i][j+1].isWalkable() && !theFloor[i][j+1].getPiece()) { x = i; y = j+1;
 } else if((j-1 >= 0) && theFloor[i][j-1].isWalkable() && !theFloor[i][j-1].getPiece()) {
         x = i; y = j - 1; } else  if((i+1 <= height) && theFloor[i+1][j].isWalkable() && !theFloor[i+1][j].getPiece()) {
         x = i + 1; y = j; 
       } else  if((i+1 <= height) && (j-1 >= 0) && theFloor[i+1][j-1].isWalkable() && !theFloor[i+1][j-1].getPiece()){
         x = i + 1; y = j - 1;
       } else  if((i+1 <= height) && (j+1 <= width) && theFloor[i+1][j+1].isWalkable() && !theFloor[i+1][j+1].getPiece()){
         x = i + 1; y = j + 1;
       } else  if((i-1 >= 0) && theFloor[i-1][j].isWalkable() && !theFloor[i-1][j].getPiece()) {
         x = i - 1; y = j; 
       } else  if((i-1 >= 0) && (j-1 >= 0) && theFloor[i-1][j-1].isWalkable() && !theFloor[i-1][j-1].getPiece()){
         x = i - 1; y = j - 1;
       } else  if((i-1 >= 0) && (j + 1 <= width) && theFloor[i-1][j+1].isWalkable() && !theFloor[i-1][j+1].getPiece()){
         x = i - 1; y = j + 1;
       } else {
       }

       if(x != i || y != j) {
       theFloor[i][j].getPiece()->move_enemy(x,y);
        theFloor[x][y].addPiece(theFloor[i][j].getPiece());
        theFloor[i][j].removePiece();
        i = x;
        j = y;
 }
     break;
     }
      }
     }
   }
 }

}
*/

// }

 void Floor::movePlayer(Direction dir) {
    int row = player->getY() + dir.relativeY;
    int col = player->getX() + dir.relativeX;
    
	if(theFloor[row][col].getType() == 'P') {
		//decorate the player with the potion
		theFloor[player->getY()][player->getX()].removePiece();
		player = theFloor[row][col].getPiece()->addPotion(player);
		theFloor[row][col].addPiece(player);
    }
    if(theFloor[row][col].getType() == 'G') {
			//decorate the player with the gold if it's available
			if ((theFloor[row][col].getPiece())->isAvailable()) {
				theFloor[player->getY()][player->getX()].removePiece();
        player = theFloor[row][col].getPiece()->addGold(player);
       	theFloor[row][col].addPiece(player);
			} else {
				// hit dragon hoard with alive dragon
				theFloor[row][col].getPiece()->attackThief(player);
			}
    }
	if(theFloor[row][col].getPiece() && theFloor[row][col].getPiece()->getType() == 'E') {
		cout << "hit enemy" << endl;
		player->attack(theFloor[row][col].getPiece());
                cout<<theFloor[row][col].getPiece()->getHP() <<endl;
                cout<< theFloor[row][col].getPiece()->isSlain() <<endl;
	}
    if(theFloor[row][col].isWalkable() && !theFloor[row][col].getPiece()) {
       theFloor[row][col].addPiece(player);
       theFloor[player->getY()][player->getX()].removePiece();
       player->move(dir.relativeX, dir.relativeY);
    }
 }

// bool Floor::isPlayerDead() {
//     return player->isSlain(); 
// }

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
   }
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
   out << "Race: " << c << " Gold: " << f.player->getGold() <<endl;
   out << "HP: " << f.player->getHP() << endl;
   out << "Atk: " << f.player->getatk() << endl;
   out << "Def: " << f.player->getDef() << endl;
   out << "Action: "; 

   return out;
}

