#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;  
	
	
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


int getTotal(int array[][COLS], int rows)
{

}


double getAverage(int array[][COLS], int rows)
{
    
}


int getRowTotal(int array[][COLS], int rowToTotal)
{

}


int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
	
}


int getHighestInRow(int array[][COLS], int rowToSearch)
{
     
}


int getLowestInRow(int array[][COLS], int rowToSearch)
{
	
}

