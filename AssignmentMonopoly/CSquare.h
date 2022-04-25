//Alex Vanellis
//bellow make sure that CSquare header is not included twice at compilation
#pragma once
#include <string>
#include <vector>

//class forward declaration
class Player;

using namespace std;

//class definitions
class CSquare
{
	//CSquare properties
private:

	int squareType;
	string squareName;
	bool mortgaged = false; //default value

public:

	//constructor
	CSquare(int type, string name);

	//getters:
	int GetSquareType();
	string GetSquareName();
	bool GetMortgaged();

	//setters
	void SetSquareType(int newType);
	void SetSquareName(string newName);
	void SetMortgaged(bool mortgaged);

	//methods
	static shared_ptr<CSquare> CreateSquareFromString(const string& input); //return smart pointer
	virtual bool Land(Player* player, Player* otherPlayer); //to be overidden 
	virtual int ColourGroup(); //to be overidden 
	virtual int SquareCost(); //to be overidden 

};