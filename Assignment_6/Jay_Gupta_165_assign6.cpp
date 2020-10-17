#include<iostream>
using namespace std;

const int ROWS = 3;  
const int COLS = 3;  
const int MIN  = 1;  
const int MAX  = 9;  

void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

int main()
{
  
   int magicArray[ROWS][COLS] = { {4, 9, 2},
                                  {3, 5, 7},
                                  {8, 1, 6} };

  
   int normalArray[ROWS][COLS] = { {10, 2, 3},
                                   {4, 15, 6},
                                   {7, 8, -8} };
                                   

   showArray(normalArray);
   showResult(normalArray);
 
   showArray(magicArray);
   showResult(magicArray);

   system("PAUSE");
   return 0;
}


void showResult(int values[][COLS])
{
   
   if (isMagicSquare(values))
   {
     .
      cout << "This is a Lo Shu magic square.\n\n";
   }
   else
   {
      
      cout << "This is not a Lo Shu magic square.\n\n";
   }
}


void showArray(int values[][COLS])
{

   for (int row = 0; row < ROWS; row++)
   {
      for (int col = 0; col < COLS; col++)
      {
       
         cout << values[row][col] << " ";
      }

    
      cout << endl;
   }
}


bool isMagicSquare(int values[][COLS])
{   
 
}

bool checkRange(int values[][COLS])
{
   
}


bool checkUnique(int values[][COLS])
{
  
}


bool checkRowSum(int values[][COLS])
{
 
}


bool checkColSum(int values[][COLS])
{
    
}


bool checkDiagSum(int values[][COLS])
{
  
}
