//Alex Vanellis
#include "Property.h" //include header file for Property definition
#include "CSquare.h"
#include "Player.h"
/*provide implementation for signatures declared in the header*/

//Constructor
Property::Property(int type, string name, int cost, int rent, int colorGroup) : CSquare(type, name) { //initialize base properties
	/*initialize additional child properties*/
	this->propertyCost = cost;
	this->propertyRent = rent;
	this->propertyColorGroup = colorGroup;
}

//Getters
int Property::GetPropertyCost() {
	return this->propertyCost;
}
int Property::GetPropertyRent() {
	return this->propertyRent;
}
int Property::GetPropertyColorGroup() {
	return this->propertyColorGroup;
}
//virtual 
int Property::ColourGroup() {
	return this->propertyColorGroup;
}
int Property::SquareCost() {
	return this->propertyCost;
}

//Setters
void Property::SetPropertyCost(int newCost) {
	this->propertyCost = newCost;
}
void Property::SetPropertyRent(int newRent) {
	this->propertyRent = newRent;
}
void Property::SetPropertyColorGroup(int newColorGroup) {
	this->propertyColorGroup = newColorGroup;
}

//Methods
bool Property::Land(Player* player, Player* otherPlayer) {

	//output where player lands
	cout << player->GetName() << " lands on " << this->GetSquareName() << endl;

	if (player->checkIfSquareOwned(player, this)) { //check if player already owns square
		return false; //nothing happens
	}

	//check if other player owns it and not mortgage -> pay rent
	if (player->checkIfSquareOwned(otherPlayer, this) && !player->checkIfSquareMortgaged(otherPlayer, this)) {

		//identify if double rent due to color group
		int overallRent = player->checkIfGroupOwned(otherPlayer, this) ? this->GetPropertyRent() * 2 : this->GetPropertyRent();

		if (player->GetMoney() < overallRent) { //can't afford rent

			/*Mortgage process*/
			int i = 0; //counter
			while (player->GetMoney() < overallRent) {

				if (i >= player->GetPlayerSquares().size()) { //no more properties
					return true; //bankrupt
				}

				//add to mortgaged -> add to balance
				player->GetPlayerSquares().at(i)->SetMortgaged(true); //change square state
				player->addMortgagedSquare(player->GetPlayerSquares().at(i)); //add to mortgaged properties
				player->SetNewMoney(player->GetMoney() + player->GetPlayerSquares().at(i)->SquareCost()); //add
				cout << player->GetName() << " Mortgages " << player->GetPlayerSquares().at(i)->GetSquareName() << endl; //ouput message
				i++; //increment counter

			}	
		}
		
		//landed player can NOW afford rent
		if (player->GetMoney() - overallRent > 0) {
			player->SetNewMoney(player->GetMoney() - overallRent); //deduct due to rent
		}
		else {
			player->SetNewMoney(0); //avoid going into 0 //rare case
		}
		//add to other player's money
		otherPlayer->SetNewMoney(otherPlayer->GetMoney() + overallRent);
		cout << player->GetName() << " pays " << overallRent << endl;
	}
	else {

		//square not owned and can be purchased
		if (!player->checkIfSquareOwned(otherPlayer, this)) {

			if (player->GetMoney() - this->SquareCost() > 0) { // check if enough funds
				
				player->SetNewMoney(player->GetMoney() - this->SquareCost()); //deduct funds
				player->addSquare(this); //add property to current player's properties
				cout << player->GetName() << " buys " << this->GetSquareName() << " for " << this->SquareCost() << endl;																				/*DEBUG*/
			}
			else {
				cout << player->GetName() << " does not have enough funds to buy " << this->GetSquareName() << endl;
			}
		}
		else {
			//the property is owned but mortgaged
			cout << player->GetName() << " does not pay rent for " << this->GetSquareName() << endl;
		}
	}

	return false; //not bankrupt
}
