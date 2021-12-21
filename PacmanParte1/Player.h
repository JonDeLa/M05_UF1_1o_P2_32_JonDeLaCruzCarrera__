#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include "Enemy.h"
#include <vector>
enum USER_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
class Player
{
	COORD Respawn;
	COORD dir;
	char character = 'O';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_YELLOW;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
public:
	COORD pos;
	int points = 0;
	Player(COORD _spawn);
	void Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies);
	void Kill(Map* _map);
	void Draw();

};

