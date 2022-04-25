//Alex Vanellis
#include "Board.h"

//initialize board
Board::Board(const string& monopolyFile) {

	ifstream file(monopolyFile); //file with square info
	string info; //store each line
	int counter = 0; //index of array

	//check if file is valid
	if (!file) {
		cout << "unable to open file"; //for user
	}

	while (getline(file, info)) //read line by line
	{

		shared_ptr<CSquare> square = CSquare::CreateSquareFromString(info); //fetch data into the alocated square -> return square

		this->squares.push_back(square); //add polymorphic square

	}

};

//Getter
vector<shared_ptr<CSquare>> Board::GetBoard() {

	return this->squares;

};