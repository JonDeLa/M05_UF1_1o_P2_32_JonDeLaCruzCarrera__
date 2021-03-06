#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include"TimeManager.h"
#include<stdlib.h>
#include<time.h>
class  Enemy
{
	
	//<summary>
	//Posici?n y direcci?n COORD es como si fuera un Vector 2
	//</summary>
	COORD pos;
	COORD Respawn;
	COORD dir;
	//Estas variables es para el contador de PowerUp
	float pu_countdown =0;
	const float pu_countdown_Time = 15;
	//<summary>
	//Este sera el como se imprime el enemigo
	//</summary>
	char character = 'e';
	//<summary>
	//Cambiamos colores de background y foreground con un enum de ConsoleUtils
	//</summary>
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;

	ConsoleUtils::CONSOLE_COLOR foreground_attack = ConsoleUtils::CONSOLE_COLOR::RED;
	ConsoleUtils::CONSOLE_COLOR foreground_powerup = ConsoleUtils::CONSOLE_COLOR::CYAN;
	void RandomDir();
	//<summary>
	// Con el Public hacemos que todo lo que esta abajo nos lo ponga en publico
	//</summary>
	
public:
	//<summary>
	// Vamos a generar un cosntructor
	//</summary>
	Enemy();
	Enemy(COORD _spawn); 
	enum ENEMY_STATE{ENEMY_NONE,ENEMY_KILLED,ENEMY_KILL};
	void Draw();
	void PowerUpActive();
	ENEMY_STATE Update(Map* _map, COORD _player);

};