//Alex Vanellis 
#include "GameManager.h"
#include "Board.h"
#include "Player.h"

//Constructor
GameManager::GameManager(const string& monopolyFile, const string& seedFile, int rounds) {

	this->board = make_unique<Board>(monopolyFile); //initialize board

	/*initialize seed */
	ifstream file(seedFile); //file just has some sentences
	string data; //line from file tmp

	//check if file is valid
	if (!file) cout << "unable to open file"; //for user
	
	while (getline(file, data)) //read line by line (we need first line only)
	{
		this->SEED = stoi(data); //assign value from string to the seed
	}

	/*initialize players */
	this->red = make_unique<Player>("Dog", 1500, 0); //red = Dog
	this->green = make_unique<Player>("Car", 1500, 0); //green = Car

	this->ROUNDS = rounds; //Set desired number of rounds

}

//Methods
void GameManager::start() {

	cout << "Welcome to Monopol-ish" << endl << endl; //welcome message

	srand(this->SEED); //apply seed 

	//game mechanics
	while (this->ROUNDS > 0) { //game loop

		/*progress players*/
		cout << endl << "ROUND: " << 51 - this->ROUNDS << endl; //round message
		cout << "----------" << endl;

		//if tru is returned player is bankrupt -> perform for 2 players
		if (this->red->play(this->board.get(), this->green.get())) { //red play 
			cout << this->red->GetName() << " Declared Bankrupt " << endl;
			cout << this->green->GetName() << " Wins " << endl; //other player wins
			break;
		};
		if (this->green->play(this->board.get(), this->red.get())) { //green play
			cout << this->green->GetName() << " Declared Bankrupt " << endl;
			cout << this->red->GetName() << " Wins " << endl;
			break;
		};

		this->ROUNDS--; //reduce rounds

		if (this->ROUNDS == 0) { //if rounds end //output game over messages
			cout << endl << "Game Over" << endl;
			cout << this->red->GetName() << " has $" << this->red->GetMoney() << endl;
			cout << this->green->GetName() << " has $" << this->green->GetMoney() << endl;

			//identify who won and output message
			this->red->GetMoney() > this->green->GetMoney() ? cout << this->red->GetName() << " Wins! " << endl : cout << this->green->GetName() << " Wins!" << endl;
		}
	}
}