#include <iostream>
using namespace std;

const int COLS = 5;

// function prototypes 
// 1. The array parameter has 'const' as they are all 
// read-only; they don't need more permissions to do their functionality. 
int getTotal(const int array[][COLS], int rows); 
double getAverage(const int array[][COLS], int rows); 
int getRowTotal(const int array[][COLS], int rowToTotal); 
int getColumnTotal(const int array[][COLS], int colToTotal, int rows); 
int getHighestInRow(const int array[][COLS], int rowToSearch); 
int getLowestInRow(const int array[][COLS], int rowToSearch); 

int main() {
	
	const int ROWS = 4;  
	
	// 2. This is the 2-D array that will be used throughout the program. 
	int testArray[ROWS][COLS] =
					{ { 1,   2,  3,  4,  5 },
					{   6,   7,  8,  9, 10 },
					{  11,  12, 13, 14, 15 },
					{  16,  17, 18, 19, 20 } };
	
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;

	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;

	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;

	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;

	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;

	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;
        
    system("PAUSE");
	return 0;
}


int getTotal(const int array[][COLS], int rows) {
	// 3. To get the total, this function first declares a sum variable, 
	// and then, the outer loop goes through the rows, and the inner 
	// loop goes through the columns. 

	int total = 0; 

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			total += array[i][j]; 
		}
	}

	return total; 
}


double getAverage(int array[][COLS], int rows) {
	// 4. To find the average, this function first totals 
	// all of the values, and then, multiplies the number of columns 
	// by the number of rows to get the total number of elements. 
	// The average is total divided by number of elements. 

	int total = 0; 

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			total += array[i][j]; 
		}
	}

	int numberOfElements = COLS * rows; 

	// 5. Cast numberOfElements to a double in order to get 
	// the result in the form of a double, instead of an integer.  
	double average = total / (double) numberOfElements; 

	return average; 
}


int getRowTotal(int array[][COLS], int rowToTotal) {
	// 6. To find the row total, first declare a 'total' variable; 
	// then, loop through the columns to get the values in that row,
	// adding them to the total variable.  

	int total = 0; 

	for (int j = 0; j < COLS; j++) {
		total += array[rowToTotal][j]; 
	}

	return total; 
}


int getColumnTotal(int array[][COLS], int colToTotal, int rows) {
	// 7. To find the column total, first, have a total variable, and 
	// loop through the rows, adding the current value to the total. 
	int total = 0; 
	
	for (int i = 0; i < rows; i++) {
		total += array[i][colToTotal]; 
	}

	return total; 
}


int getHighestInRow(int array[][COLS], int rowToSearch) {
    // 8. First, have a variable for highest 
	// Then, loop through the row using a different col value to find highest; 
	// if the current number is greater than highest, set highest to this new value. 

	// 9. Setting the intitial value of highest to the first value of the array is 
	// important, as setting it to a constant number such as 0 can lead to an error; 0 may be 
	// greater than all of the values in the array, but may not be a value present in the array. 
	int highest = array[rowToSearch][0]; 

	for (int j = 0; j < COLS; j++) {
		if (highest < array[rowToSearch][j]) {
			highest = array[rowToSearch][j]; 
		}
	}

	return highest; 
}


int getLowestInRow(int array[][COLS], int rowToSearch) {
	// 10. This is the same functionality as above, but for lower. This means that 
	// if the current value is less than lowest, set lowest to this value. 
	int lowest = array[rowToSearch][0]; 

	for (int j = 0; j < COLS; j++) {
		if (lowest > array[rowToSearch][j]) {
			lowest = array[rowToSearch][j]; 
		}
	}

	return lowest;
}