#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include "textdisplay.h"
#include "tile.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int width, int height) : width{width}, height{height} {
  init();
}

void TextDisplay::init() {
	map.assign(height, vector<char>(width, ' '));	
	ifstream ifsmap(mapfile);
	string line;
	char tileType;
	for (int r = 0; r < height; r++) {
		getline(ifsmap, line);
		for (int c = 0; c < width; c++) {
			map[r][c] = line[c];
		}
	}

}

void TextDisplay::notify(Subject &whoNotified) {
	//whoNotified is a type
	Info tile = whoNotified.getInfo();
	map[tile.row][tile.col] = tile.type;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int r = 0; r < td.height; r++) {
		for (int c = 0; c < td.width; c++) {
			out << td.map[r][c];
		}
		out << endl;
	}
	out << endl;
	return out;
	
}
