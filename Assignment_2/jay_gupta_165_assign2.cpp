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

int main()
{
	// set seed for rand() using time  
	// rand() should only be seeded once, which
	// is why it is being done here, at the 
	// start of the program
	srand(time(0)); 

	cout << getComputerChoice(); 

	// My Tests:
	// int userChoice = getUserChoice();
	// displayChoice(1); 

	// int userChoice;		
	// int computerChoice;	

	// computerChoice = getComputerChoice();

	// userChoice = getUserChoice();

	// while (userChoice != QUIT)
	// {
		
	// 	cout << "\nYou selected: ";
	// 	displayChoice(userChoice);
	// 	cout << "The computer selected: ";
	// 	displayChoice(computerChoice);
		
	// 	determineOutcome(userChoice, computerChoice);
	// 	cout<<endl;

	// 	computerChoice = getComputerChoice();

	// 	userChoice = getUserChoice();
	// }

	system("PAUSE");
	return 0;
}

// no input parameters 
// returns the computer's choice (1, 2, or 3)
int getComputerChoice()
{
	// generate a random number from 1-3
	int computerChoice = 1 + (rand() % 3); 
	
	return computerChoice; 
}

// no input parameters
// returns the user's choice (1, 2, 3, or 4)
int getUserChoice()
{
    // display the game menu to the user
	cout << endl << "Game Menu" << endl; 
	cout << "---------" << endl; 
	cout << "1) Rock" << endl; 
	cout << "2) Paper" << endl; 
	cout << "3) Scissors" << endl; 
	cout << "4) Quit" << endl << endl; 

	// prompt user for choice from 1-4
	int userChoice; 
	cout << "Enter your choice: "; 
	cin >> userChoice; 

	// while userChoice falls outside the range of 1-4, 
	// keep on prompting the user for a valid selection 
	while (userChoice < 1 || userChoice > 4) {
		cout << "Invalid selection. Enter 1, 2, 3, or 4: "; 
		cin >> userChoice; 
	}

	// returns user's choice (1, 2, 3, or 4)
	return userChoice; 
}


void determineOutcome(int user, int computer)
{
	
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
