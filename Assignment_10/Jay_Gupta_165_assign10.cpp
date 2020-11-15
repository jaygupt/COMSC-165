#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// add prototypes for your functions
void readDataFromFileIntoArray(char* ptr); 
void createReportBasedOnData(const char* ptr); 

// program constants
const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;

int main() {

	// this 2D array stores the 90 values from the RainOrShine.txt text file
	// rows represent months, columns represent days
	char weather[NUM_OF_MONTHS][NUM_OF_DAYS];

	char* ptr = &weather[0][0]; // this pointer points to the beginning of the 2D array
	                            // Remember -- no using the brackets/subscripts ([]'s)! 
	                            // Everything should be handled with pointer offset notation
	                            // and/or pointer arithmetic
   
	//implement the rest of main
	
	// read data from file into array
	readDataFromFileIntoArray(ptr);

	// TEST to see if array has values
	// for (int i = 0; i < NUM_OF_MONTHS; i++) {
	// 	for (int j = 0; j < NUM_OF_DAYS; j++) {
	// 		cout << weather[i][j] << endl; 
	// 	}
	// }

	// based on data, create statistics
	// createReportBasedOnData(ptr);  

	// system("PAUSE");
	return 0;
}

// implement your functions
void readDataFromFileIntoArray(char* ptr) {
	// using a second, temporary pointer to use pointer 
	// arithmetic on
	char* secondPtr = nullptr; 
	secondPtr = ptr; 

	// create an object of the file
	ifstream weatherFile("RainOrShine.txt");

	if (!weatherFile) {
		// the file wasn't able to be opened
		cout << "Error in Opening File." << endl;
	} else {
		// the file successfully opened
		
		// store the current reading in currentForecast
		char currentForecast; 
		while (weatherFile >> currentForecast) {
			*secondPtr = currentForecast; 
			secondPtr++; 
		} 
	}

	weatherFile.close(); 
}

void createReportBasedOnData(const char* ptr) {
	// display July days
}