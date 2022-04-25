//Alex Vanellis
#pragma once
#include <iostream>

//Game headers
#include "CSquare.h"
#include "Player.h"

class Jail : public CSquare { //base properties and public methods invoked

private:
public:

	/*Constructor*/   
	Jail(int type, string name);

	//Methods
	bool Land(Player* player, Player* otherPlayer);

};
