#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
class Tile;

class TextDisplay: public Observer {
	std::vector<std::vector<char>> map;
	int width, height;
	std::string mapfile = "Floor/floor.txt";

	void init();

	public:
		TextDisplay(int width, int height);
		~TextDisplay() = default;

		void notify(Subject &whoNotified) override;

		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
