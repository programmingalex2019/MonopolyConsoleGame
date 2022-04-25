//Alex Vanellis
#pragma once
#include <iostream>

//Game headers
#include "Player.h"
#include "CSquare.h"

//change vector definition to custom names
typedef vector<string> PenaltyMessages;
typedef vector<int> PenaltyMoney;

class Penalty : public CSquare { //base properties and public methods invoked

private:

	PenaltyMessages penaltyMessages; //vector of string messages
	PenaltyMoney penaltyMoney; //vectory of int money to pay

public:

	/*Constructor*/
	Penalty(int type, string name);

	//Methods
	bool Land(Player* player, Player* otherPlayer);

};
