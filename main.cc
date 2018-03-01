#include <iostream>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Floor/floor.h"
#include "direction.h"

using namespace std;

int main(int argc, char *argv[]) {
	srand (time(NULL));
	Floor f;
	string cmd;
	bool isPaused = false;
	map<char, string> playerNames = {
		{'s', "Shade"},
		{'d', "Drow"},
		{'v', "Vampire"},
		{'t', "Troll"},
		{'g', "Goblin"}
	};

	cout << "Welcome to ChamberCrawler3000!" << endl;

	cout << "Choose your character:" << endl;
	for (auto it = playerNames.begin(); it != playerNames.end(); it++)
		cout << it->first << " - " << it->second << endl;

	while (cin >> cmd) {
		if (playerNames.count(cmd[0]) == 1) {
			f.spawnPlayer(cmd[0]);	
			break;
		} else if (cmd == "q") {
			return 0;
		}

		cout << "Please enter a valid character name" << endl;
	}

	f.spawnPieces();
	cout << f;
    cout << "Player character has spawned." << endl;
	cout << "Direction commands: no, ne, ea, se, so, sw, we, nw." << endl;
	cout << "Enter a command:" << endl;
	while (cin >> cmd) {
		if (f.compass.count(cmd) == 1) {
			f.movePlayer(f.compass[cmd]);
			//	cout << "You have conquered the dungeon!" << endl;
                      	cout <<f;
		} else if (cmd == "a") {
			cin >> cmd;
			f.playerAttack(f.compass[cmd]);
		} else if (cmd == "u") {
                        cin >> cmd;
                        f.potionUse(f.compass[cmd]);
		} else if (cmd == "f") {
			isPaused = !isPaused;
		} else if (cmd == "r") {
			//restarts game
		} else if (cmd == "q") {
			return 0;
		} else {
			continue;
		}
		
		if (!isPaused) { f.moveEnemies(); }
		if (f.isPlayerDead()) { break; }
		if (f.isWinner()) { break; }
                cout << f;
        } 

	cout << "Thanks for playing!" << endl;
}

