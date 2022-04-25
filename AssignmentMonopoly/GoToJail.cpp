//Alex Vanellis
#include "GoToJail.h" //include header file for Property definition
#include "CSquare.h"

//Constructor
GoToJail::GoToJail(int type, string name) : CSquare(type, name) {

}

//Methods
bool GoToJail::Land(Player* player, Player* otherPlayer) {

	//output where player lands
	cout << player->GetName() << " lands on " << this->GetSquareName() << endl;

	//sent player to jail and let player roll until even next round
	if (player->GetMoney() < 50) { //can't afford rent
		player->SetRentJail(true); // change jail state
		player->SetJailPosition(6); //move to jail
		cout << player->GetName() << " cannot pay fee and goes to Jail " << endl;
	}
	else {
		//Pay fee - do not remain in jail next round
		cout << player->GetName() << " goes to Jail " << endl;
		cout << player->GetName() << " pays 50 " << endl;
		player->SetNewMoney(player->GetMoney() - 50); //deduct money
		player->SetJailPosition(6); //move to jail
	}

	return false;
}
