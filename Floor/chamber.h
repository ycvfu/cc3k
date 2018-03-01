#ifndef CHAMBER_H
#define CHAMBER_H
#include "position.h"
#include <vector>
class Tile;

class Chamber {
public:
	std::vector<Position> theChamber;	//the positions of all the tiles 
									//that fall into this chamber

   		Chamber();
		int numTiles;
   		void addTile(int row, int col);	//adds position of tile to chamber 
   		Position randomizeTile();	//returns the position of a randomly 
   									//selected tile from this chamber

};

#endif
