#include <iostream>
using namespace std;


void print_array(const char arr[], int size);
bool is_palindrome(const char arr[], int size);
void display_result(bool result);

// returns true if array is palindrome otherwise false
// pointer notation/arithmetic 

int main()
{

	const int SIZE = 12;
	const int SIZE2 = 7;

	bool result;

	// this array IS a palindrome
	char arr[SIZE] = 
	{
		'A', 'B', 'C', 'D',
		'E', 'F', 'F', 'E', 
		'D', 'C', 'B', 'A'
	};

	cout << *(arr + 1) << endl; 

	// this array is NOT palindrome
	char arr2[SIZE] = {
	
	'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L' 
	
    };


	// this array is NOT palindrome
	char arr3[SIZE] = 
	{
		'A', 'B', 'C', 'D',
		'E', 'R', 'Z', 'E',
		'D', 'C', 'B', 'A'
	};


	// this array IS a palindrome
	char arr4[SIZE2] = 
	{

	 'R', 'A', 'C', 'E',
	 'C', 'A', 'R'

	};

	// if the size is odd. 
	// if the size is even, goes halfway 
	// *(i + 1)

	print_array(arr, SIZE);
	result = is_palindrome(arr, SIZE);
	display_result(result);


	print_array(arr2, SIZE);
	result = is_palindrome(arr2, SIZE);
	display_result(result);


	print_array(arr3, SIZE);
	result = is_palindrome(arr3, SIZE);
	display_result(result);
	
	
	print_array(arr4, SIZE2);
	result = is_palindrome(arr4, SIZE2);
	display_result(result);
	

	system("PAUSE");
	return 0;
}


void print_array(const char arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " "; 
	}

	cout << endl; 
}


bool is_palindrome(const char arr[], int size)
{
	for (int i = 0; i < (size / 2); i++) {
		if (*(arr + i) != *(arr + size - i - 1)) {
			return false; 
		}
	}

	return true; 
}

void display_result(bool result)
{
	if (result)
		cout << "Yes, the 2D array is a palindrome\n\n";

	else
		cout << "No, the 2D array is NOT a palindrome\n\n";

}
