#include "Enemy.h"

void Enemy::RandomDir()
{
	dir = { 0,0 };
	int rndm = rand() % 4;
	switch (rndm)
	{
	case 0:
		dir.X = 1;
		break;
	case 1:
		dir.X = -1;
		break;
	case 2:
		dir.Y = 1;
		break;
	case 3:
		dir.Y = -1;
		break;
	
	}
}

//<summary>
// Definimos variables de la clase.
//</summary>
Enemy::Enemy()
{
	pos = { 0,0};
	dir = { 0,0 };
}

Enemy::Enemy(COORD _spawn)
{
	pos = _spawn;
	dir = { 0,0 };
}

void Enemy::Draw()
{
	ConsoleUtils::Console_SetPos(pos);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void Enemy::Update(Map* _map)
{
	RandomDir();
	COORD newPos = pos;
	newPos.X += dir.X;
	newPos.Y += dir.Y;

	if (newPos.X < 0)
	{
		newPos.X = _map->Width - 1;
	}
	newPos.X %= _map->Width;
	if (newPos.Y < 0)
	{
		newPos.Y = _map->Height - 1;
	}
	newPos.Y %= _map->Height;

	switch (_map->GetTile(newPos.X, newPos.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPos = pos;
		break;
	}
	pos = newPos;
}
