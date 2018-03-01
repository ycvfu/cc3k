#include "chamber.h"
#include "position.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Chamber::Chamber() : numTiles{0} {
	theChamber.resize(100);
}

void Chamber::addTile(int row, int col) {
	theChamber.emplace_back(Position{row, col});
	numTiles++;
	cout << numTiles << endl;
}

Position Chamber::randomizeTile() {
	cout << "ch1" << endl;
	cout << numTiles << endl;
	int randTile = rand() % numTiles;
	cout << "ch2" << endl;
	return theChamber[randTile];
}

    
