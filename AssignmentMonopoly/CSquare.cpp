//Alex Vanellis
#include "CSquare.h" //include header file for CSquare definition
#include "Property.h"
#include "Player.h"
#include "Jail.h"
#include "GoToJail.h"
#include "FreeParking.h"
#include "Station.h"
#include "Bonus.h"
#include "Penalty.h"
#include <sstream>
#include <vector>

/*provide implementation for signatures declared in the header*/

//Constructor 
CSquare::CSquare(int type, string name) {
	this->squareType = type;
	this->squareName = name;
};

//Getters
int CSquare::GetSquareType() {
	return this->squareType;
}
string CSquare::GetSquareName() {
	return this->squareName;
}
bool CSquare::GetMortgaged() {
	return this->mortgaged;
}

//Setters
void CSquare::SetSquareType(int newType) {
	this->squareType = newType;
}
void CSquare::SetSquareName(string newName) {
	this->squareName = newName;
}
void CSquare::SetMortgaged(bool mortgaged) {
	this->mortgaged = mortgaged;
}

//Methods // will be overidden by children classes
bool CSquare::Land(Player* player, Player* otherPlayer) { //virtual

	cout << player->GetName() << " lands on " << this->squareName << endl;
	return false;

}

//will be overidden by children classes
int CSquare::ColourGroup() {
	return -1;
}
int CSquare::SquareCost() {
	return 0;
}

//create smart pointer squares from string of square data
shared_ptr<CSquare> CSquare::CreateSquareFromString(const string& input) {

	string s, tmp, temp = ""; //temporary variables for splitting strings
	vector<string> squareInfo; //vector to split square info words
	shared_ptr<CSquare> square;

	//split string algorithm
	for (int i = 0; i < input.length(); ++i) {

		if (input[i] == ' ') {
			squareInfo.push_back(temp); //word identified
			temp = ""; //reset temp for next word
		}
		else {
			temp.push_back(input[i]); //push character unti space found
		}

	}
	squareInfo.push_back(temp); //push word split by whitespace

	/*Generate Squares*/
	int type = stoi(squareInfo.at(0)); //identify type of square

	//generate square based on type
	switch (type) {

	case 1:

		//Property
		square = make_shared<Property>
		(
			type,
			squareInfo.at(1) + " " + squareInfo.at(2),
			stoi(squareInfo.at(3)),
			stoi(squareInfo.at(4)),
			stoi(squareInfo.at(5))
		);
		break;

	case 2:

		//GO
		square = make_shared<CSquare>(type, squareInfo.at(1));
		break;

	case 3:

		//Station
		square = make_shared<Station>(type, squareInfo.at(1) + " " + squareInfo.at(2), 200, 10); //predefined characteristics
		break;

	case 4:

		//Bonus
		square = make_shared<Bonus>(type, squareInfo.at(1));
		break;

	case 5:

		//Penalty
		square = make_shared<Penalty>(type, squareInfo.at(1));
		break;

	case 6:

		//Jail
		square = make_shared<Jail>(type, squareInfo.at(1));
		break;

	case 7:

		//Go To Jail
		square = make_shared<GoToJail>(type, squareInfo.at(1) + " " + squareInfo.at(2) + " " + squareInfo.at(3));
		break;

	case 8:

		//Car Wash
		square = make_shared<FreeParking>(type, squareInfo.at(1) + " " + squareInfo.at(2));
		break;

	default:

		//Default
		square = make_shared<CSquare>(type, squareInfo.at(1) + " " + squareInfo.at(2));

	}

	return square;
};
