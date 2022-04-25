//Alex Vanellis
#pragma once //Player header is not included twice at compilation
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//Game headers
using namespace std;

//class forward declarations
class Board;
class CSquare;
class Property;

//change vector definition to custom names
typedef vector<CSquare*> PlayerSquares;
typedef vector<CSquare*> PlayerMortgagedSquares;

class Player {

private:
	string name;
	int money;
	int position; //on board
	PlayerSquares playerSquares; //everything owned
	PlayerMortgagedSquares mortgagedProperties; //what is mortgaged
	bool RENT_JAIL; //if player is sent to Jail due to low balance against rent or penalty

public:
	
	//constructor
	Player(string newName, int newMoney, int newPosition);

	//Getters
	string GetName();
	int GetMoney();
	int GetPosition();
	bool GetRentJail();
	PlayerSquares GetPlayerSquares();
	PlayerMortgagedSquares GetPlayerMortgagedSquares();

	//Setters
	void SetNewMoney(int newMoney);
	bool SetNewPosition(int rolled); //bool will identify if playeer passed GO
	void SetRentJail(bool newRentJail);
	void SetJailPosition(int position);
	void addSquare(CSquare* newSquare);
	void addMortgagedSquare(CSquare* newMortgagedSquare);
	void removePlayerSquare(int index);
	void removeMortgagedSquare(int index);

	//Methods
	bool play(Board* board, Player* otherPlayer); //performed each round
	bool checkIfSquareOwned(Player* otherPlayer, CSquare* square);
	bool checkIfSquareMortgaged(Player* otherPlayer, CSquare* square);
	bool checkIfGroupOwned(Player* otherPlayer, CSquare* square);

};

