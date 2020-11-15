#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// add prototypes for your functions


    const int NUM_OF_MONTHS = 3;
	const int NUM_OF_DAYS = 30;


int main()
{

	// this 2D array stores the 90 values from the RainOrShine.txt text file
	char weather[NUM_OF_MONTHS][NUM_OF_DAYS];

	char* ptr = &weather[0][0]; // this pointer points to the beginning of the 2D array
	                            // Remember -- no using the brackets/subscripts ([]'s)! 
	                            // Everything should be handled with pointer offset notation
	                            // and/or pointer arithmetic
   
	//implement the rest of main
	

	system("PAUSE");
	return 0;
}

// implement your functions
