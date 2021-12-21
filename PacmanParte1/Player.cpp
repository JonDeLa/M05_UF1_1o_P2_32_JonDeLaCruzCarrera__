#include "Player.h"

Player::Player(COORD _spawn)
{
	pos = _spawn;
	dir = { 0,0 };
	Respawn = _spawn;
}

void Player::Update(Map* _map, USER_INPUTS input, std::vector<Enemy>* enemies)
{
    COORD newPos = pos;
    
    switch (input)
    {
    case UP:
        newPos.Y--;
        break;
    case DOWN:
        newPos.Y++;
        break;
    case RIGHT:
        newPos.X++;
        break;
    case LEFT:
        newPos.X--;
        break;
    
    }
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
        newPos.Y = pos.Y;
        newPos.X = pos.X;
        break;
    case Map::MAP_TILES::MAP_POINT:
        _map->points--;
        points++;
        _map->SetTile(newPos.X, newPos.Y, Map::MAP_TILES::MAP_EMPTY);
        break;
    case Map::MAP_TILES::MAP_POWERUP:

       points += 25;

        for (size_t i = 0; i < enemies->size(); i++)
        {
            enemies->at(i).PowerUpActive();
        }
        //enemy01.PowerUpActive();

        _map->SetTile(newPos.X, newPos.Y, Map::MAP_TILES::MAP_EMPTY);
        break;

    }

    pos = newPos;
}

void Player::Kill(Map* _map)
{
    points -= 50;
    pos.X = _map->spawn_player.X;
    pos.Y = _map->spawn_player.Y;
}


void Player::Draw()
{
	ConsoleUtils::Console_SetPos(pos);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}
