//Alex Vanellis
#include "Player.h" //include header file for Player definition
#include "Board.h"

//constructor
Player::Player(string newName, int newMoney, int newPosition) {
	this->name = newName;
	this->money = newMoney;
	this->position = newPosition;
	RENT_JAIL = false; //default value
}

//Getters
string Player::GetName() {
	return this->name;
};
int Player::GetMoney() {
	return this->money;
};
int Player::GetPosition() {
	return this->position;
};
bool Player::GetRentJail() {
	return this->RENT_JAIL;
}
PlayerSquares Player::GetPlayerSquares() {
	return this->playerSquares;
}
PlayerMortgagedSquares Player::GetPlayerMortgagedSquares() {
	return this->mortgagedProperties;
}

//Setters
void Player::SetNewMoney(int newMoney) {
	this->money = newMoney;
}
void Player::SetRentJail(bool newRentJail) {
	this->RENT_JAIL = newRentJail;
}

//bool is used to identify if player passed GO
bool Player::SetNewPosition(int rolled) { // when passed -> add to current postion

	if (this->GetPosition() + rolled >= 26) {

		this->position = (this->GetPosition() + rolled) - 26; //Start from beggining
		return true;
	}
	else {
		this->position += rolled; //move player
		return false;
	}
}

//change players position directly to jail
void Player::SetJailPosition(int position) {
	this->position = position;
}

//add to owned squares
void Player::addSquare(CSquare* newSquare) {

	this->playerSquares.push_back(newSquare);

	//sort vector when square added -> for mortgaging process 
	sort(this->playerSquares.begin(), this->playerSquares.end(), [](CSquare* a, CSquare* b)
		{
			return a->SquareCost() < b->SquareCost();
		});
}

void Player::removePlayerSquare(int index) {
	this->playerSquares.erase(this->playerSquares.begin() + index);
}
void Player::removeMortgagedSquare(int index) {
	this->mortgagedProperties.erase(this->mortgagedProperties.begin() + index);
}

void Player::addMortgagedSquare(CSquare* newMortgagedSquare) {

	this->mortgagedProperties.push_back(newMortgagedSquare);

	//sort vector when square added -> for de-mortgaging process 
	sort(this->mortgagedProperties.begin(), this->mortgagedProperties.end(), [](CSquare* a, CSquare* b)
		{
			return a->SquareCost() < b->SquareCost();
		});
}

//Methods
bool Player::checkIfSquareOwned(Player* otherPlayer, CSquare* square) {

	for (CSquare* i : otherPlayer->GetPlayerSquares()) { //go throw each owned property

		//check if propery exists in other players's properties
		if (i->GetSquareName().compare(square->GetSquareName()) == 0) { //0 means equal
			return true;
		}

	}
	return false;
};

bool Player::checkIfSquareMortgaged(Player* otherPlayer, CSquare* square) {

	for (CSquare* i : otherPlayer->GetPlayerSquares()) { //go throw each owned property

		//check if propery exists in other players's properties
		if (i->GetSquareName().compare(square->GetSquareName()) == 0) { //0 means equal
			if (i->GetMortgaged()) { //identify if square mortgaged
				return true;
			}else {
				return false;
			}
		}

	}
	return false;
};

//identify if a colour group was completed
bool Player::checkIfGroupOwned(Player* otherPlayer, CSquare* square) {

	int group = 0;

	for (CSquare* i : otherPlayer->GetPlayerSquares()) { 

		if (i->ColourGroup() == square->ColourGroup()) { //property
			group += 1;
		}
	}

	//specific requirement conditions whether group completed
	if (square->ColourGroup() == 3 || square->ColourGroup() == 6) {
		return group == 3 ? true : false;
	}else return group == 2 ? true : false;

};

//performed each player's turn
bool Player::play(Board* board, Player* otherPlayer) {

	//roll dice
	int roll = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);

	//display message 
	cout << this->name << " rolls " << roll << endl;

	//Player in Jail Due to Rent
	if (this->GetRentJail() && roll >= 2 && roll % 2 == 0) {
		
		cout << this->name << " receives a presedential pardon and is free to go" << endl;
		this->SetRentJail(false); //proceed on board

	}
	else if (this->GetRentJail() && !(roll >= 2 && roll % 2 == 0)) { //remain in jail
		
		cout << this->name << " remains in jail" << endl;
		return false; //skip turn
	}

	//progress player on the board
	bool PassedGo = this->SetNewPosition(roll);

	if (PassedGo) { //back at GO
		this->SetNewMoney(this->GetMoney() + 200);
		cout << this->name << " passes GO and collects 200" << endl; //message
	}

	//once player has ability to pay firts mortaged property -> declare square
	if (this->mortgagedProperties.size() > 0 && this->money > this->mortgagedProperties.at(0)->SquareCost()) {

		for (CSquare* square : this->playerSquares) {
			if (square->GetSquareName().compare(this->mortgagedProperties.at(0)->GetSquareName()) == 0) { //identify which square was repayed
				square->SetMortgaged(false); //other player will now pay rent if lands
				break;
			}
		}

		cout << this->GetName() << " Repays " << this->mortgagedProperties.at(0)->GetSquareName() << " mortgage in full" << endl;

		this->removeMortgagedSquare(0); //remove from mortgage now can rent

	}

	//figure out landed square //figure out if land resulted in true -> player bankrupt
	bool anyBankrupt = board->GetBoard().at(this->GetPosition())->Land(this, otherPlayer); //pass current player

	cout << this->GetName() << " has " << this->GetMoney() << endl << endl; //display balance

	return anyBankrupt;
}
