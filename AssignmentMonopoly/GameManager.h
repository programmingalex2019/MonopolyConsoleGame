//Alex Vanellis
#pragma once

//c++ Libraries
#include <iostream>
#include <vector> //manipulate board

//Game headers
#include "Board.h"
#include "Player.h"

using namespace std; //avoid using std throughout the class

//class to manage game states and main game loop
class GameManager {

private:

	//unique smart pointer will be deleted automatically
	unique_ptr<Board> board;
	unique_ptr<Player> red;
	unique_ptr<Player> green;
	int ROUNDS; //keep track of round
	int SEED = 1; //Default value

public:

	//Constructor
	GameManager(const string& monopolyFile, const string& seedFile, int rounds); //initialize monopoly board and players

	//Methods
	void start(); //start the game

};