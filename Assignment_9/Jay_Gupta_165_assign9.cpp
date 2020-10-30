#include <iostream>
using namespace std;

// function prototypes 
int getMode(int*, int);
int* makeArray(int);

int main() {	
	// variable declarations 
	const int SIZE = 9;
	int test[SIZE] = {5, 4, 11, 10, 10, 10, 11, 11, 10}; 
	// int test[SIZE] = {1, 8, 3, 8, 3, 2, 8, 1, 8, 4, 5};
	// int test[SIZE] = {1, 2, 7, 3, 3, 7, 2, 1, 7, 4, 7};
	int mode;

	// get the mode using the test array and size constant 
	mode = getMode(test, SIZE);

	// if mode is set to -1, the array has no mode. else, 
	// there was a mode  
	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: " 
		     << mode << endl;

    // system("PAUSE");
	return 0;
}

// array passed by pointer
int getMode(int *array, int size) {
	// stores how many times the corresponding value  
	// occurs in test array 
	// for instance, if test[1] = 3, frequencies[1] stores how many times
	// 3 occurs in the test array 
	int* frequencies = makeArray(size); // intially points at first element in array 

	// populate the frequencies array 
	for (int i = 0; i < size; i++) {
		// stores the current value from "array", corresponding to index i
		int currentValue = *(array + i); 

		int occurrences = 0; 
		
		// loop through entire array to find how many times currentValue
		// appears in test; increment occurrences variable accordingly
		for (int j = 0; j < size; j++) {
			if (currentValue == *(array + j)) {
				occurrences++; 
			}
		}

		// store value of occurrences at index i of frequencies. 
		*(frequencies + i) = occurrences; 
	}

	for (int i = 0; i < size; i++) {
		cout << *(frequencies + i) << " "; 
	}
	
	// find highest's index in frequencies
	// to start the comparison, select the zeroeth index 
	int highestIndex = 0; 

	// from the first index until the end 
	for (int i = 1; i < size; i++) {
		// if the value of frequencies at index i is greater than 
		// the value of frequencies at the current highestIndex,
		if (*(frequencies + i) > *(frequencies + highestIndex)) {
			// set highestIndex to this new index i
			highestIndex = i; 
		}
	}

	// find mode using highestIndex
	int mode = *(array + highestIndex); 
	
	delete[] frequencies; // Do NOT remove this -- this needs to be at the end of the function
	                       // to remove the dynamically allocated frequencies array from memory
	                       // when it is no longer needed.
	if (mode == 1) {
		return -1; 
	} 

	return mode; 
}



// makeArray has been completed
int* makeArray(int size) {
	return new int[size];
}





