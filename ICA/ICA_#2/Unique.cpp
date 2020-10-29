#include <iostream>
using namespace std;

void print_array(const char * ptr, int size);
bool is_unique(const char * ptr, int size);
void display_result(bool result);

int main() {
	const int SIZE = 7;
	const int SIZE2 = 10;

	bool result;

	// this array is NOT unique
	const char arr[SIZE] =
	{
		'A', 'B', 'C', 'D',
		'E', 'F', 'A'
	};
	
	

	// this array IS unique
	const char arr2[SIZE] =
	
	{
	
	'A', 'B', 'C', 'D',
		'E', 'F', 'G'
	
    };


	// this array is NOT unique
	const char arr3[SIZE2] = 
	{
		'Z', 'A', 'Y',
		 'Y', 'A', 'B',
		 'H', 'J', 'R', 'X'
	};


	// this array IS unique
	const char arr4[SIZE2] =
	{

	 'A', 'Z', 'X', 'Y',
	 'R', 'C', 'V',
	 'T', 'W', 'F'

	};


	print_array(arr, SIZE);
	result = is_unique(arr, SIZE);
	display_result(result);


	print_array(arr2, SIZE);
	result = is_unique(arr2, SIZE);
	display_result(result);


	print_array(arr3, SIZE);
	result = is_unique(arr3, SIZE);
	display_result(result);
	
	
	print_array(arr4, SIZE2);
	result = is_unique(arr4, SIZE2);
	display_result(result);
	

	// system("PAUSE");
	return 0;
}

// can't change what value of what ptr points at; 
// can still do pointer arithmetic
void print_array(const char * ptr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << " "; 
	} 

	cout << endl; 
}

// can't change value of what ptr is pointing at 
bool is_unique(const char * ptr, int size)
{ 
	// This is another pointer that can be used
	// ptr2 
	const char* ptr2 = nullptr;

	// we are going through the array 
	for (int i = 0; i < size - 1; i++) {
		// from the element to the right of the current until the end of the array,
		// check if there is a match. if there is, it is a duplicate
		for (int j = i + 1; j < size; j++) {
			if (*(ptr + i) == *(ptr + j)) {
				return false; 
			}
		}
	}

	return true; 

}

void display_result(bool result)
{
	if (result)
		cout << "Yes, the 2D array is unique (no duplicates)\n\n";

	else
		cout << "No, the 2D array is NOT unique (has duplicates)\n\n";

}
