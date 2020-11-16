#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// 1. These are the program constants. TYPES_OF_WEATHER will
// be used when generating the report, and displaying it.
const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;
const int TYPES_OF_WEATHER = 3; 

// 2. These are the prototypes for the functions. It follows 
// the principle of least priviledge; i.e. displaying a report 
// doesn't require the function to change the original values, 
// hence, const is used.
void readDataFromFileIntoArray(char* ptr); 
void createReportBasedOnData(const char* data, int* const reportPtr);
void displayReport(const int* reportPtr); 

int main() {

	// this 2D array stores the 90 values from the RainOrShine.txt text file
	// rows represent months, columns represent days
	char weather[NUM_OF_MONTHS][NUM_OF_DAYS];
	char* ptr = &weather[0][0]; // this pointer points to the beginning of the 2D array
	                            // Remember -- no using the brackets/subscripts ([]'s)! 
	                            // Everything should be handled with pointer offset notation
	                            // and/or pointer arithmetic

	//implement the rest of main
	
	// 3. Read the data from RainOrShine.txt into the weather array
	// using the pointer. Pointer, as a result, has no const constraints.
	readDataFromFileIntoArray(ptr);

	// 4. Based on the data, create a report. Because the function
	// increments based on previous values in the array, we  
	// initialize report to have values of 0
	int report[NUM_OF_MONTHS][TYPES_OF_WEATHER] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};
	int* reportPtr = &report[0][0]; 

	// 5. Create and display the resulting report. createReport function
	// doesn't return anything, as pointers are automatically "passed by reference".
	createReportBasedOnData(ptr, reportPtr);

	displayReport(reportPtr); 
	
	return 0;
}

void readDataFromFileIntoArray(char* ptr) {
	// 6. Using a second, temporary pointer to use pointer 
	// arithmetic on. If we did it on ptr, it wouldn't be ideal, 
	// as it is the only pointer that points at the beginning of the
	// weather array
	char* secondPtr = nullptr; 
	secondPtr = ptr;  

	// 7. Create an object of the file using ifstream.
	ifstream weatherFile("RainOrShine.txt");

	// 8. Test to see if opening the file was successful. 
	if (!weatherFile) {
		// the file wasn't able to be opened
		cout << "Error in Opening File." << endl;
	} else {
		// the file successfully opened
		
		// 9. While reading the file, 
		// store the current reading in currentForecast
		char currentForecast; 
		while (weatherFile >> currentForecast) {
			*secondPtr = currentForecast; 
			secondPtr++; 
		} 
	}

	weatherFile.close(); 
}

void createReportBasedOnData(const char* data, int* const reportPtr) {
	// 10. The goal for this function is to store in report:
	// Report Result:
	// 11 8 11
	// 11 14 5
	// 16 7 7

	const char* secondPtr = nullptr; 
	secondPtr = data; 

	// 11. Go through the weather array (by referencing secondPtr) and fill 
	// report array appropriately
	for (int i = 0; i < 90; i++) {
		// 12. Each if block going from 0 to 30 represents a month.
		if (i >= 0 && i < 30) {
			// 13. Depending on the value of *secondPtr, increment a particular
			// value in the report array.
			if (*secondPtr == 'R') {
				*(reportPtr) = *(reportPtr) + 1; 
			} else if (*secondPtr == 'C') {
				*(reportPtr + 1) = *(reportPtr + 1) + 1;  
			} else {
				*(reportPtr + 2) = *(reportPtr + 2) + 1; 
			}
		} else if (i >= 30 && i < 60) {
			if (*secondPtr == 'R') {
				*(reportPtr + 3) = *(reportPtr + 3) + 1;  
			} else if (*secondPtr == 'C') {
				*(reportPtr + 4) = *(reportPtr + 4) + 1;  
			} else {
				*(reportPtr + 5) = *(reportPtr + 5) + 1; 
			}
		} else {
			if (*secondPtr == 'R') {
				*(reportPtr + 6) = *(reportPtr + 6) + 1;  
			} else if (*secondPtr == 'C') {
				*(reportPtr + 7) = *(reportPtr + 7) + 1;  
			} else {
				*(reportPtr + 8) = *(reportPtr + 8) + 1; 
			}
		}

		secondPtr++; 
	}

}

void displayReport(const int* reportPtr) {
	// 14. Add totals for displaying at the bottom. 
	int rainyTotal = *(reportPtr) + *(reportPtr + 3) + *(reportPtr + 6); 
	int cloudyTotal = *(reportPtr + 1) + *(reportPtr + 4) + *(reportPtr + 7);
	int sunnyTotal = *(reportPtr + 2) + *(reportPtr + 5) + *(reportPtr + 8); 

	string rainiestMonth; 

	if (*(reportPtr) > *(reportPtr + 3) && *(reportPtr) > *(reportPtr + 6)) {
		rainiestMonth = "June"; 
	} else if (*(reportPtr + 3) > *(reportPtr) && *(reportPtr + 3) > *(reportPtr + 6)) {
		rainiestMonth = "July"; 
	} else if (*(reportPtr + 6) > *(reportPtr) && *(reportPtr + 6) > *(reportPtr + 3)) {
		rainiestMonth = "August"; 
	} else {
		rainiestMonth = "All months had an equal amount of rainy days."; 
	}
	
	cout << endl << "    Summer Weather Report	" << endl << endl; 
	cout << "Month 	Rainy	Cloudy	Sunny" << endl; 
	cout << "_____________________________" << endl;
	cout << "June\t " << *(reportPtr) << "\t   " << *(reportPtr + 1) << "\t " << *(reportPtr + 2) << endl; 
	cout << "July\t " << *(reportPtr + 3) << "\t  " << *(reportPtr + 4) << "\t  " << *(reportPtr + 5) << endl;
	cout << "August\t " << *(reportPtr + 6) << "\t   " << *(reportPtr + 7) << "\t  " << *(reportPtr + 8) << endl;
	cout << "_____________________________" << endl;
	cout << "Totals\t " << rainyTotal << "\t  " << cloudyTotal << "\t " << sunnyTotal << endl << endl; 
	cout << rainiestMonth << " had the most rainy days." << endl << endl; 
}