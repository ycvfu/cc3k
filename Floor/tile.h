#ifndef TILE_H
#define TILE_H
#include "../Pieces/Characters/character.h"
#include "subject.h"
class Info;

class Tile : public Subject {
	int row, col;
	Character *occupier;
	char type;	//the type of the tile
						//this is what will be displayed 

	bool m_isWalkable;	//depends on the type of tile not occupier 

	public:
		Tile();
		~Tile();
		Info getInfo() const override;
		bool isWalkable();	//returns true if the type of the tile is walkable
		bool hasOccupier();	//returns true if the tile is occupied 
		bool isBlocked();	//returned true if the tile is occupied or the tile is not walkable
		bool isBlockingEnemy();
		bool isEnemyBlocked();
		void setCoords(int row, int col);
		void setType(char type);
		char getType() const;
		void addPiece(Character *piece);
		void removePiece();	//does not call delete 
		Character* getPiece();
};

#endif
