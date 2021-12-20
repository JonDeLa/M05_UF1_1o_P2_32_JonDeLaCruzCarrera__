#include "Enemy.h"

//<summary>
// Definimos variables de la clase.
//</summary>
Enemy::Enemy()
{
	pos = { 12,10 };
	dir = { 0,0 };
}

Enemy::Enemy(COORD _spawn)
{
	pos = { _spawn };
	dir = { 0,0 };
}

void Enemy::Draw()
{
	ConsoleUtils::Console_SetPos(pos);
	ConsoleUtils::Console_SetColor(foreground,background);
	std:: cout << character;
}
