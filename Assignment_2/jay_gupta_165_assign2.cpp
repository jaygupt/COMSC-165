#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

int getUserChoice();
int getComputerChoice();
void determineOutcome(int, int);
void displayChoice(int);

// TODO: Number Comments 
// TODO: 5 Screenshots of sample runs 

int main()
{
	// 1. set seed for rand() using time  
	// rand() should only be seeded once, which
	// is why it is being done here, at the 
	// start of the program
	srand(time(0)); 

	int userChoice;		
	int computerChoice;	

	computerChoice = getComputerChoice();

	userChoice = getUserChoice();

	while (userChoice != QUIT)
	{	
		cout << "\nYou selected: ";
		displayChoice(userChoice);
		cout << "\nThe computer selected: ";
		displayChoice(computerChoice);

		cout << endl << endl;
		
		determineOutcome(userChoice, computerChoice);
		cout << endl;

		computerChoice = getComputerChoice();
		userChoice = getUserChoice();
	}

	system("PAUSE");
	return 0;
}

// 2. no input parameters 
// returns the computer's choice (1, 2, or 3)
int getComputerChoice()
{
	// 3. generate a random number from 1-3
	// rand() % 3: generates a random number
	// from 0 to 2
	int computerChoice = 1 + (rand() % 3); 
	
	if (computerChoice == 1) {
		return ROCK; 
	} else if (computerChoice == 2) {
		return PAPER; 
	} else {
		return SCISSORS; 
	} 
}

// 4. no input parameters
// returns the user's choice (1, 2, 3, or 4)
int getUserChoice()
{
    // 5. display the game menu to the user
	cout << endl << "Game Menu" << endl; 
	cout << "---------" << endl; 
	cout << "1) Rock" << endl; 
	cout << "2) Paper" << endl; 
	cout << "3) Scissors" << endl; 
	cout << "4) Quit" << endl << endl; 

	// 6. prompt user for choice from 1-4
	int userChoice; 
	cout << "Enter your choice: "; 
	cin >> userChoice; 

	// 7. while userChoice falls outside the range of 1-4, 
	// keep on prompting the user for a valid selection 
	while (userChoice < 1 || userChoice > 4) {
		cout << "Invalid selection. Enter 1, 2, 3, or 4: "; 
		cin >> userChoice; 
	}

	// 8. returns user's choice (1, 2, 3, or 4)
	if (userChoice == 1) {
		return ROCK; 
	} else if (userChoice == 2) {
		return PAPER; 
	} else if (userChoice == 3) {
		return SCISSORS; 
	} else {
		// userChoice == 4
		return QUIT; 
	}
}

// input: user's choice (1, 2, or 3) and computer's choice (1, 2, or 3)
// output: displays using 'cout' who the winner is, or if there was a tie
void determineOutcome(int user, int computer)
{
	// ways to win
	// rock beats scissors (1 vs. 3)
	// scissors beats paper (3 vs. 2)
	// paper beats rock (2 vs. 1)

	// tie 
	if (user == computer) {
		cout << "Tie. No winner."; 
	} else if (user == ROCK && computer == SCISSORS) {
		// user selects rock, computer selects scissors 
		cout << "YOU win! Rock smashes scissors."; 
	} else if (computer == ROCK && user == SCISSORS) {
		// same as above but user and computer are reversed
		cout << "Computer wins! Rock smashes scissors."; 
	} else if (user == SCISSORS && computer == PAPER) {
		// user selects scissors, computer selects paper 
		cout << "YOU win! Scissors cuts paper."; 
	} else if (computer == SCISSORS && user == PAPER) {
		// same as above but user and computer are reversed
		cout << "Computer wins! Scissors cuts paper."; 
	} else if (user == PAPER && computer == ROCK) {
		// user selects paper, computer selects rock 
		cout << "YOU win! Paper wraps rock."; 
	} else {
		// same as above but user and computer are reversed
		cout << "Computer wins! Paper wraps rock.";  
	}
}

// input: user's or computer's choice (1, 2, or 3)
// output: displays using 'cout' rock, paper, or scissors 
// depending on the number given
void displayChoice(int choice)
{
	if (choice == 1) {
		cout << "Rock"; 
	} else if (choice == 2) {
		cout << "Paper"; 
	} else {
		// choice has to be 3
		cout << "Scissors"; 
	}
}
