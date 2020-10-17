#include<iostream>
using namespace std;

// declare global constants
const int ROWS = 3;  
const int COLS = 3;  
const int MIN = 1;  
const int MAX = 9;  

// function prototypes 
void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

// custom function prototypes 
bool valueInArray(int valueInQuestion, int theArray[]); 

int main() {
   int magicArray[ROWS][COLS] = { {4, 9, 2},
                                  {3, 5, 7},
                                  {8, 1, 6} };
  
   int normalArray[ROWS][COLS] = { {10, 2, 3},
                                   {4, 15, 6},
                                   {7, 8, -8} }; 
   
   // custom test-array
   int testArray[ROWS][COLS] = { {3, 1, 2}, 
                                 {4, 5, 6}, 
                                 {7, 8, 9}}; 

   // showArray(normalArray);
   // showResult(normalArray);
 
   // showArray(magicArray);
   // showResult(magicArray);

   system("PAUSE");
   return 0;
}


void showResult(int values[][COLS]) {
   if (isMagicSquare(values)) {
      cout << "This is a Lo Shu magic square.\n\n";
   } else {   
      cout << "This is not a Lo Shu magic square.\n\n";
   }
}


void showArray(int values[][COLS]) {
   for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLS; col++) {
         cout << values[row][col] << " ";
      }

      cout << endl;
   }
}

bool isMagicSquare(int values[][COLS]) {   
 
}

// accepts a two-dimenstional int array as an argument
bool checkRange(int values[][COLS]) {
   // returns true if values are within specified range (1 - 9)
   // otherwise, returns false 

   // loop through array; if a value is less than min, 
   // or greater than max, return false 
   // at the end, return true 

   // loop through rows
   for (int i = 0; i < ROWS; i++) {
      // loop through columns
      for (int j = 0; j < COLS; j++) {
         if (values[i][j] < MIN || values[i][j] > MAX) {
            // the array value is not in the range of 1 - 9
            return false; 
         }
      }
   }

   // all of the array values are in the range of 1 - 9
   return true; 
}

// accepts a two-dimenstional int array as an argument
bool checkUnique(int values[][COLS]) {
   // if the values in the array are unique, returns true
   // else, returns false (this means there are duplicates)

   // naive solution: 
   // have a single dimensional array of "used elements"
   // while going through the 2D array, check if the value in 
   // question is already in the used array. If it is, then 
   // it is a duplicate, and return false. If it isn't, 
   // add it to the array for future reference
   // at the end, return true, as the whole array in question
   // has unique values 

   int usedElements[MAX]; 

   // loop through array's rows
   for (int i = 0; i < ROWS; i++) {
      // loop through array's columns 
      for (int j = 0; j < COLS; j++) {
         int valueInQuestion = values[i][j]; 

         // valueInArray function will check if valueInQuestion is 
         // in usedElements. If it is, that means the value is a 
         // duplicate. 
      }
   }
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

// accepts two parameters: value to look for, and the array
// that is being searched in
bool valueInArray(int valueInQuestion, int theArray[]) {
   // purpose: finds whether or not the valueInQuestion is in theArray
   // if the value occurs in theArray, returns true
   // else, returns false 
}