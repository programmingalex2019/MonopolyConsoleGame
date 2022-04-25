//Alex Vanellis
#include "Penalty.h" //include header file for Property definition
#include "CSquare.h"
/*provide implementation for signatures declared in the header*/

//constructor
Penalty::Penalty(int type, string name) : CSquare(type, name) {

	//add to vector list of messages
	this->penaltyMessages.push_back("Buy a coffee. Lose 20.");
	this->penaltyMessages.push_back("Pay your broadband bill. Lose 50.");
	this->penaltyMessages.push_back("Donate to charity. Lose 100.");
	this->penaltyMessages.push_back("Loose your wallet. Lose 150.");
	this->penaltyMessages.push_back("Go for a romantic meal. Lose 200.");
	this->penaltyMessages.push_back("Pay university fees. Lose 300.");

	//list of integers -> money to pay
	this->penaltyMoney.push_back(20);
	this->penaltyMoney.push_back(50);
	this->penaltyMoney.push_back(100);
	this->penaltyMoney.push_back(150);
	this->penaltyMoney.push_back(200);
	this->penaltyMoney.push_back(300);
}

//Methods
bool Penalty::Land(Player* player, Player* otherPlayer) {

	//output where player lands
	cout << player->GetName() << " lands on : " << this->GetSquareName() << endl;

	//roll dice
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);

	//penalty message
	cout << this->penaltyMessages.at(roll - 1) << endl;

	//update player money
	if (player->GetMoney() < this->penaltyMoney.at(roll - 1)) { //cant afford penalty
		player->SetRentJail(true); //change to jail state for next time roll
		player->SetJailPosition(6); //change position of player
		cout << player->GetName() << " cannot pay penalty and goes to Jail " << endl; //message
	}
	else {
		player->SetNewMoney(player->GetMoney() - this->penaltyMoney.at(roll - 1)); //deduct money if can afford
	}

	return false; //not bankrupt
}
