//Alex Vanellis
#include "Bonus.h" //include header file for Property definition
#include "CSquare.h"
/*provide implementation for signatures declared in the header*/

//Default constructor


/*Parameterized constructors (overloading)*/
Bonus::Bonus(int type, string name) : CSquare(type, name) {

	//add to vector list of messages
	this->bonusMessages.push_back("Find some money. Gain 20.");
	this->bonusMessages.push_back("Win a coding competition Gain 50.");
	this->bonusMessages.push_back("Receive a donation. Gain 100.");
	this->bonusMessages.push_back("Win the lottery. Gain 150.");
	this->bonusMessages.push_back("It is your name day. Gain 200.");
	this->bonusMessages.push_back("It is your birthday. Gain 300.");

	//list of integers -> money to receive
	this->bonusMoney.push_back(20);
	this->bonusMoney.push_back(50);
	this->bonusMoney.push_back(100);
	this->bonusMoney.push_back(150);
	this->bonusMoney.push_back(200);
	this->bonusMoney.push_back(300);

}

//Methods
bool Bonus::Land(Player* player, Player* otherPlayer) {

	//output where player lands
	cout << player->GetName() << " lands on : " << this->GetSquareName() << endl;

	//roll dice
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
	
	//bonus message
	cout << this->bonusMessages.at(roll-1) << endl;

	//update player money
	player->SetNewMoney(player->GetMoney() + this->bonusMoney.at(roll-1));
	return false; //not bankrupt
}
