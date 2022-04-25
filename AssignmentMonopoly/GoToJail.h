//Alex Vanellis
#pragma once
#include <iostream>

//Game headers
#include "Player.h"
#include "CSquare.h"

class GoToJail : public CSquare { //base properties and public methods invoked

private:
public:

	/*Constructor*/
	GoToJail(int type, string name);

	//Methods
	bool Land(Player* player, Player* otherPlayer);

};
