//Alex Vanellis
#pragma once
#include <iostream>

//Game headers
#include "Player.h"
#include "CSquare.h"

class Station : public CSquare { //base properties and public methods invoked

	//Property properties
private:
	int stationCost;
	int stationFee;
	int stationColorGroup;
public:

	/*Constructor*/
	Station(); //default constructor   
	Station(int type, string name, int stationCost, int stationFee);

	//Getters
	int GetStationCost();
	int GetStationFee();
	int GetStationColorGroup();
	//will be overriden
	int SquareCost();

	//Setters
	void SetStationCost(int newCost);
	void SetStationRent(int newRent);
	void SetStationColorGroup(int newColorGroup);

	//Methods
	bool Land(Player* player, Player* otherPlayer);
};

