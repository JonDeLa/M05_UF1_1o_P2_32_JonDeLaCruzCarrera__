#pragma once
#include "ConsoleUtils.h"
class  Enemy
{
	//<summary>
	//Posición y dirección COORD es como si fuera un Vector 2
	//</summary>
	COORD pos;
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
	//<summary>
	// Con el Public hacemos que todo lo que esta abajo nos lo ponga en publico
	//</summary>
	
public:
	//<summary>
	// Vamos a generar un cosntructor
	//</summary>
	Enemy();
	Enemy(COORD _spawn); 
	void Draw();


};