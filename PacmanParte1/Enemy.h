#pragma once
#include "ConsoleUtils.h"
#include "Map.h"

#include<stdlib.h>
#include<time.h>
class  Enemy
{
	
	//<summary>
	//Posición y dirección COORD es como si fuera un Vector 2
	//</summary>
	COORD pos;
	COORD Respawn;
	COORD dir;
	//<summary>
	//Este sera el como se imprime el enemigo
	//</summary>
	char character = 'e';
	//<summary>
	//Cambiamos colores de background y foreground con un enum de ConsoleUtils
	//</summary>
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::BLACK;
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
	ENEMY_STATE Update(Map* _map, COORD _player);

};