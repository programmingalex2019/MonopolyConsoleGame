//Alex Vanellis
#include <iostream>
//memory leak libraries
#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>

//Game
#include "GameManager.h"

int main()
{

	GameManager* game = new GameManager("monopoly.txt", "seed.txt", 50); //create game
	game->start(); //start game
	delete game; //dealocate game
	_CrtDumpMemoryLeaks(); //identify memory leaks

}
