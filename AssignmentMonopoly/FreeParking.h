//Alex Vanellis
#pragma once
#include <iostream>

//Game headers
#include "Player.h"
#include "CSquare.h"

class FreeParking : public CSquare { //base properties and public methods invoked

private:
public:

	/*Constructor*/
	FreeParking(int type, string name);

	//Methods
	bool Land(Player* player, Player* otherPlayer);


};
