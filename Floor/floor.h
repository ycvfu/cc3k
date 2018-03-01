#ifndef FLOOR_H
#define FLOOR_H
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include "textdisplay.h"
#include "tile.h"
#include "../direction.h"
#include "../Pieces/Characters/Players/player.h"
#include "../Pieces/Characters/Enemies/enemy.h"
struct Position;

class Floor {
   std::vector <Position> Chamber1;
   std::vector <Position> Chamber2;
   std::vector <Position> Chamber3;
   std::vector <Position> Chamber4;
   std::vector <Position> Chamber5;

   const std::string mapfile = "Floor/floor.txt";
   const std::string chambersfile = "Floor/chambers.txt";
   const int width = 79;
   const int height = 25;

   int floorNum;
   std::vector <std::vector <Tile>> theFloor;
   std::vector<Enemy *> enemies;
	// I really just don't like the below
   // std::vector<std::vector<Position>> chambers;    //keeps track of the tiles 
                                 			 		  //belonging to each of the 5 chambers
   Player * player;
   TextDisplay *textdisplay;

   void readMap();   
   void createChambers();
   Position randomizeTile();
   Direction randomizeDir();
   void spawnStairs();
   void spawnPotions();
   void spawnTreasures();
   void spawnEnemies();
   void nextFloor();
   bool isEnemySurrounded(Enemy *enemy);
   void move(Character *character, Direction dir);
   bool isWon; 
   bool playerIsClose(Enemy* enemy);

   public:
   Floor();
   ~Floor();

   // void readPieces(string filename);   //if the user provided a file
   //                                     //use that instead of spawning Pieces 
   void spawnPieces();
   void spawnPlayer(char type);
   void movePlayer(Direction dir);
   void moveEnemies();
   // void usePotion(Direction dir);
   // void attackMonster(Direction dir);
   // void pause();
    bool isPlayerDead();
    bool isWinner();
   // &Tile getTile(int row, int col);
   // void dropGold(int row, int col, Treasure * drop); // use by Enemy to drop gold when slain
   void playerAttack(Direction dir);
   void potionUse(Direction dir);
   static std::map<std::string, Direction> compass;
	 int getFloorNum() const;
   friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};
   
    
#endif 
