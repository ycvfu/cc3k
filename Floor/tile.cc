#include "tile.h"
#include "info.h"
#include <iostream> //move

Tile::Tile() : occupier{nullptr}, m_isWalkable{false} {}

Tile::~Tile() {
if(occupier) {
delete occupier;
}
}

bool Tile::isWalkable() {
	return m_isWalkable;
}

bool Tile::hasOccupier() {
	return occupier != nullptr;
}

bool Tile::isBlocked() {	
	return (hasOccupier() || !isWalkable() || type == '/');
}

bool Tile::isEnemyBlocked() {
	return (hasOccupier() || type != '.');
}

bool Tile::isBlockingEnemy() {
    return ((hasOccupier() && getType()!='@') || type!='.');
}

void Tile::setCoords(int row, int col) {
	this->row = row;
	this->col = col;
}

void Tile::setType(char type) {
	switch (type) {
        //case ' ': m_isWalkable = false; break;	//empty
        case '+': m_isWalkable = true; break;	//door
        case '.': m_isWalkable = true; break;	//tile
        //case '-': m_isWalkable = false; break;	//wall
        case '#': m_isWalkable = true; break;	//passage
        //case '|': m_isWalkable = false; break;	//wall
        //case '/': m_isWalkable = false; break;	//stairs
    }
	this->type = type;
	notifyObservers();	//notify display
}

char Tile::getType() const {
	if (occupier) { return occupier->canPrintType(); }
	return type;
}

Info Tile::getInfo() const {
	char type = getType();
	return Info{row, col, type};
}

void Tile::addPiece(Character *piece) {
 	occupier = piece;
        notifyObservers();	//notify display 
}

void Tile::removePiece() {
 	occupier = nullptr;
 	notifyObservers();	//notify display 
}

Character* Tile::getPiece() {
 	return occupier;
}
