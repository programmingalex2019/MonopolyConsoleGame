//Alex Vanellis
#pragma once
#include <iostream>
#include <vector>

//Game headers
#include "Player.h"
#include "CSquare.h"

//change vector definition to custom names
typedef vector<string> BonusMessages;
typedef vector<int> BonusMoney;

class Bonus : public CSquare { //base properties and public methods invoked

	//Property properties
private:

	BonusMessages bonusMessages; //vector of string messages
	BonusMoney bonusMoney; //vectory of int money to receive

public:

	/*Constructor*/
	Bonus(int type, string name);

	//Methods
	bool Land(Player* player, Player* otherPlayer);

};
