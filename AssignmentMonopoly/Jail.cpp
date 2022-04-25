//Alex Vanellis
#include "Jail.h" //include header file for Property definition
#include "CSquare.h"

//constructor
Jail::Jail(int type, string name) : CSquare(type, name) {

}

//Methods
bool Jail::Land(Player* player, Player* otherPlayer) {

	//Nothing happens output messages
	cout << player->GetName() << " lands on " << this->GetSquareName() << endl;
	cout << player->GetName() << " is just visiting" << endl;
	return false;
}
