#include <iostream>
using namespace std;


void print_array(const char * ptr, int size);
bool is_unique(const char * ptr, int size);
void display_result(bool result);


int main()
{

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
	

	system("PAUSE");
	return 0;
}


void print_array(const char * ptr, int size)
{

  // Implement this function
  // Implement this function
  // Implement this function
  // Implement this function
  // Implement this function
  
}


bool is_unique(const char * ptr, int size)
{
	
	// This is another pointer that can be used
	const char* ptr2 = nullptr;

    
	// Implement this function
	// Implement this function
	// Implement this function
	// Implement this function
	// Implement this function
	

}

void display_result(bool result)
{
	if (result)
		cout << "Yes, the 2D array is unique (no duplicates)\n\n";

	else
		cout << "No, the 2D array is NOT unique (has duplicates)\n\n";

}
