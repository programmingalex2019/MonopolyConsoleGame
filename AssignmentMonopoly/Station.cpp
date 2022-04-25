//Alex Vanellis
#include "Station.h" //include header file for Property definition
#include "CSquare.h"
/*provide implementation for signatures declared in the header*/

//constructor
Station::Station(int type, string name, int stationCost, int stationFee) : CSquare(type, name) {
	this->stationCost = stationCost;
	this->stationFee = stationFee;
}

//Getters
int Station::GetStationCost() {
	return this->stationCost;
}
int Station::GetStationFee() {
	return this->stationFee;
}
int Station::GetStationColorGroup() {
	return this->stationColorGroup;
}
//virtual
int Station::SquareCost() {
	return this->stationCost;
}

//Setters
void Station::SetStationCost(int newCost) {
	this->stationCost = newCost;
}
void Station::SetStationRent(int newRent) {
	this->stationFee = newRent;
}
void Station::SetStationColorGroup(int newColorGroup) {
	this->stationColorGroup = newColorGroup;
}

//Methods
bool Station::Land(Player* player, Player* otherPlayer) {

	//ouput where player lands
	cout << player->GetName() << " lands on " << this->GetSquareName() << endl;

	if (player->checkIfSquareOwned(player, this)) { //check if player already owns square
		return false; //nothing happens
	}

	if (player->checkIfSquareOwned(otherPlayer, this)) { //station owned by otherPlayer

		if (player->GetMoney() < this->GetStationFee()) { //can't afford rent

			/*Mortgage process*/
			int i = 0; //counter
			while (player->GetMoney() < this->GetStationFee()) {

				if (i >= player->GetPlayerSquares().size()) { //no more properties
					return true; //bankrupt
				}

				//remove from owned -> add to mortgaged -> add to balance
				player->GetPlayerSquares().at(i)->SetMortgaged(true); //change square state
				player->addMortgagedSquare(player->GetPlayerSquares().at(i));
				player->SetNewMoney(player->GetMoney() + player->GetPlayerSquares().at(i)->SquareCost()); //add to mortgaged properties
				cout << player->GetName() << " Mortgages " << player->GetPlayerSquares().at(i)->GetSquareName() << endl;
				i++; //increment counter

			}

		}

		//landed player can NOW afford fee
		if (player->GetMoney() - this->GetStationFee() > 0) {
			player->SetNewMoney(player->GetMoney() - this->GetStationFee());
		}
		else {
			player->SetNewMoney(0);
		}
		//add to other player's money
		otherPlayer->SetNewMoney(otherPlayer->GetMoney() + this->GetStationFee());
		cout << player->GetName() << " pays " << this->GetStationFee() << " for ticket" << endl;																				/*DEBUG*/
		
	}
	else {

		//square not owned and can be purchased
		if (!player->checkIfSquareOwned(otherPlayer, this)) {

			if (player->GetMoney() - this->SquareCost() > 0) { // check if enough funds

				player->SetNewMoney(player->GetMoney() - this->SquareCost()); //deduct funds
				player->addSquare(this); //add station to current player's squares
				cout << player->GetName() << " buys " << this->GetSquareName() << " for " << this->SquareCost() << endl;																				/*DEBUG*/
			}
			else {
				cout << player->GetName() << " does not have enough funds to buy " << this->GetSquareName() << endl;
			}
		}
		else {

			//the station is owned but mortgaged
			cout << player->GetName() << " does not pay rent for " << this->GetSquareName() << endl;
		}

	}

	return false; //not bankrupt

}
