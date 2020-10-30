#include <iostream>
using namespace std;

// function prototypes 
int getMode(int *array, int size);
int* makeArray(int size);

int main() {	
	// variable declarations 
	const int SIZE = 8;
	int test[SIZE] = {9, 1, 7, 2, 12, 3, 9, 5};
	int mode;

	// 1. Get the mode using the test array and size constant 
	mode = getMode(test, SIZE);

	// 2. if mode is set to -1, the array has no mode. else, 
	// there was a mode  
	if (mode == -1)
		cout << "\nThe test set has no mode.\n\n";
	else
		cout << "\nThe mode of the test set is: " 
		     << mode << endl << endl;

    // system("PAUSE");
	return 0;
}

// array passed by pointer
int getMode(int *array, int size) {
	// 3. frequencies stores how many times the corresponding value  
	// occurs in test array 
	// for instance, if test[1] = 3, frequencies[1] stores how many times
	// 3 occurs in the test array 
	int* frequencies = makeArray(size); // 4. intially points at first element in array 

	// populate the frequencies array 
	for (int i = 0; i < size; i++) {
		// 5. stores the current value from "array", corresponding to index i
		int currentValue = *(array + i); 

		int occurrences = 0; 
		
		// 6. loop through entire array to find how many times currentValue
		// appears in test; increment occurrences variable accordingly
		for (int j = 0; j < size; j++) {
			if (currentValue == *(array + j)) {
				occurrences++; 
			}
		}

		// 7. store value of occurrences at index i of frequencies. 
		*(frequencies + i) = occurrences; 
	}

	// 8. we have our frequencies; the highest frequency 
	// corresponds to mode in array 

	// 9. Set highestFrequency to 1 initially; if no mode, 
	// this will be determining mode as -1
	int highestFrequency = 1; 
	int highestFrequencyIndex = 0; 

	// 10. go through the whole frequencies array; 
	// find the largest frequency, and its corresponding index. 
	// this index will be used to find mode. 
	for (int i = 0; i < size; i++) {
		if (*(frequencies + i) > highestFrequency) {
			highestFrequency = *(frequencies + i); 
			highestFrequencyIndex = i; 
		}
	}

	int mode; 

	// 11. if no mode (highestFrequency is 1) return -1; else, 
	// return the mode
	if (highestFrequency == 1) {
		mode = -1; 
	} else {
		mode = *(array + highestFrequencyIndex); 
	}

	delete[] frequencies; // Do NOT remove this -- this needs to be at the end of the function
	                       // to remove the dynamically allocated frequencies array from memory
	                       // when it is no longer needed.

	return mode; 
}

// makeArray has been completed
int* makeArray(int size) {
	return new int[size];
}