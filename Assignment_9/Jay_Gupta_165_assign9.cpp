#include <iostream>
using namespace std;

int getMode(int*, int);
int* makeArray(int);

// main has been completed 
int main() {	
	const int SIZE = 5;
	int test[SIZE] = {2, 4, 6, 8, 10}; 
	// int test[SIZE] = {1, 8, 3, 8, 3, 2, 8, 1, 8, 4, 5};
	// int test[SIZE] = {1, 2, 7, 3, 3, 7, 2, 1, 7, 4, 7};
	int mode;

	mode = getMode(test, SIZE);
   
	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: " 
		     << mode << endl;

    // system("PAUSE");
	return 0;
}

// test passed by pointer  
int getMode(int *array, int size) {
	
	// frequencies will point at a dynamically allocated array
	// in this assignment pointer notation (i.e., using the *) should always be used instead of
	// bracket/subscript notation (i.e., using the []).
	
	// stores how many times the corresponding value  
	// occurs in test array 
	// for instance, if test[1] = 3, frequencies[1] stores how many times
	// 3 occurs in the test array 
	int* frequencies = makeArray(size); // points at first element in array 

	for (int i = 0; i < size; i++) {
		int currentValue = *(array + i); // stores the current value in test,
		// corresponding to index i

		int occurrences = 0; 
		
		// loop through whole array to find how many times currentValue
		// appears in test 
		for (int j = 0; j < size; j++) {
			if (currentValue == *(array + j)) {
				occurrences++; 
			}
		}

		// store occurrences at index i of frequencies 
		*(frequencies + i) = occurrences; 
	}
	
	// find highest in frequencies. Corresponding index in test is the mode
	int mode = -1; // set initially to -1 
	int highestIndex = 0; 

	for (int i = 1; i < size; i++) {
		if (*(frequencies + i) > *(frequencies + highestIndex)) {
			mode = *(array + i); 
		}
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





