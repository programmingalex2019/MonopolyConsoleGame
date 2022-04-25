//Alex Vanellis
#pragma once

//c++ Libraries
#include <iostream>
#include <vector> //STL
#include <fstream> //File proccessing

//Game headers
#include "CSquare.h"

class Board {

private:

	//Properties
	vector<shared_ptr<CSquare>> squares; //squares share ownernship hence shared smart pointer //will be dealocatted automatically 
	
public:

	//constructor
	Board(const string& monopolyFile); //initialize squares

	//Getter
	vector<shared_ptr<CSquare>> GetBoard();
};
