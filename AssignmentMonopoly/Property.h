//Alex Vanellis
//make sure that CSquare header is not included twice at compilation
#pragma once
#include "CSquare.h"
#include <iostream>
#include <vector>

using namespace std;

//class forward declaration
class Player;

class Property : public CSquare { //base properties and public methods invoked

	//Property properties
private:
	int propertyCost;
	int propertyRent;
	int propertyColorGroup;
public:

	/*Constructor*/
	Property(); //default constructor   
	Property(int type, string name, int cost, int rent, int colorGroup);

	//Getters
	int GetPropertyCost();
	int GetPropertyRent();
	int GetPropertyColorGroup();
	//bellow override base class virtual
	int ColourGroup();
	int SquareCost();

	//Setters
	void SetPropertyCost(int newCost);
	void SetPropertyRent(int newRent);
	void SetPropertyColorGroup(int newColorGroup);

	//Methods
	bool Land(Player* player, Player* otherPlayer); //what happens when player lands on square

};



