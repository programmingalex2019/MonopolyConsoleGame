//Alex Vanellis
#include "FreeParking.h" //include header file for Property definition
#include "CSquare.h"
/*provide implementation for signatures declared in the header*/

//constructor
FreeParking::FreeParking(int type, string name) : CSquare(type, name) {

}

//Methods
bool FreeParking::Land(Player* player, Player* otherPlayer) {

	//Pay a fee for carwash
	if (player->GetMoney() < 10) { //cant afford penalty
		player->SetRentJail(true); //change to jail state for next time roll
		player->SetJailPosition(6); //change position of player
		cout << player->GetName() << " cannot pay for Car Wash and goes to Jail " << endl; //message
	}
	else {
		//pay for car wash
		cout << player->GetName() << " lands on " << this->GetSquareName() << endl;
		cout << player->GetName() << " pays 10 for a car wash " << endl;
		player->SetNewMoney(player->GetMoney() - 10);
	}
	return false;
}
