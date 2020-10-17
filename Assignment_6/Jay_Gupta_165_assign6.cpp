#include <iostream>
#include <vector>
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
bool valueInVector(int valueInQuestion, vector<int> theVector, int vectorSize); 

int main() {
   int magicArray[ROWS][COLS] = { {1, 3, 8},
                                  {8, 5, 5},
                                  {2, 2, 6} };
  
   int normalArray[ROWS][COLS] = { {2, 1, 2},
                                   {6, 5, 1},
                                   {4, 33, 8} }; 

   cout << endl;

   showArray(normalArray);
   showResult(normalArray);
 
   showArray(magicArray);
   showResult(magicArray); 

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

// 1. accepts a two-dimenstional int array as an argument
bool isMagicSquare(int values[][COLS]) {   
   // 2. returns true if array meets all 
   // requirements of a magic square
   // else, returns false 

   if (checkRange(values) && checkUnique(values) && checkRowSum(values)
   && checkColSum(values) && checkDiagSum(values)) {
      // 3. if the array passes all of the tests
      
      return true; 
   } else {
      return false; 
   }
}

// 4. accepts a two-dimenstional int array as an argument
bool checkRange(int values[][COLS]) {
   // 5. returns true if values are within specified range (1 - 9)
   // otherwise, returns false 

   // 6. loop through array; if a value is less than min, 
   // or greater than max, return false 
   // at the end, return true 

   // loop through rows
   for (int i = 0; i < ROWS; i++) {
      // loop through columns
      for (int j = 0; j < COLS; j++) {
         if (values[i][j] < MIN || values[i][j] > MAX) {
            // 7. the array value is not in the range of 1 - 9
            return false; 
         }
      }
   }

   // all of the array values are in the range of 1 - 9
   return true; 
}

// accepts a two-dimensional int array as an argument
bool checkUnique(int values[][COLS]) {
   // 8. if the values in the array are unique, returns true
   // else, returns false (this means there are duplicates)

   // 9. naive solution: 
   // have a single dimensional array of "used elements"
   // while going through the 2D array, check if the value in 
   // question is already in the used array. If it is, then 
   // it is a duplicate, and return false. If it isn't, 
   // add it to the array for future reference
   // at the end, return true, as the whole array in question
   // has unique values 

   vector<int> usedElements; 

   // loop through array's rows
   for (int i = 0; i < ROWS; i++) {
      // loop through array's columns 
      for (int j = 0; j < COLS; j++) {
         int valueInQuestion = values[i][j]; 

         // 10. valueInArray function will check if valueInQuestion is 
         // in usedElements. If it is, that means the value is a 
         // duplicate. 

         // first, find size of usedElements
         int vectorSize = usedElements.size(); 

         if (valueInVector(valueInQuestion, usedElements, vectorSize)) {
            // valueInQuestion is a duplicate 
            return false; 
         } else {
            // 11. new value; add this value to usedElements
            usedElements.push_back(valueInQuestion); 
         }
      }
   }

   // values in 2D array are unique 
   return true; 
}

// accepts two-dimensional int array
bool checkRowSum(int values[][COLS]) {
   // 12. returns true if sum of values in each array's 
   // rows are equal; otherwise, returns false 

   // 13. find sum of first row, second row, and third row
   // if the sums aren't equal, return false
   // else, return true 

   // index 0: sum of row 1, index 1: sum of row 2, etc. 
   int sums[3] = {}; 

   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         sums[i] += values[i][j]; 
      }
   }

   if (sums[0] == sums[1] && sums[1] == sums[2]) {
      // 14. if all three row sums are equal to each other
      return true;  
   } else {
      // all three row sums aren't equal to each other 
      return false; 
   }
}

// accepts two-dimensional int array
bool checkColSum(int values[][COLS]) {
   // 15. returns true if sum of values in each array's 
   // columns are equal; otherwise, returns false 
   
   // 16. find sum of first column, second column, and third column
   // if the sums aren't equal, return false
   // else, return true 

   // index 0: sum of column 1, index 1: sum of column 2, etc. 
   int sums[3] = {}; 

   for (int j = 0; j < COLS; j++) {
      for (int i = 0; i < ROWS; i++) {
         sums[j] += values[i][j]; 
      }
   }

   if (sums[0] == sums[1] && sums[1] == sums[2]) {
      // 17. if all three column sums are equal to each other
      return true;  
   } else {
      // all three column sums aren't equal to each other 
      return false; 
   }
}

// accepts two-dimensional int array
bool checkDiagSum(int values[][COLS]) {
   // 18. calculate first diagonal sum, then second
   // if they are equal, return true
   // else, return false

   // find first diagonal sum
   int firstDiagonal = values[0][0] + values[1][1] + values[2][2]; 

   // find second diagonal sum
   int secondDiagonal = values[2][0] + values[1][1] + values[0][2]; 

   if (firstDiagonal == secondDiagonal) {
      return true; 
   } else {
      return false; 
   }
}

// accepts three parameters: value to look for, the array
// that is being searched in, and the size of the array
bool valueInVector(int valueInQuestion, vector<int> theVector, int vectorSize) {
   // 19. purpose: finds whether or not the valueInQuestion is in theArray
   // else, returns false 
   // if the value occurs in theArray, returns true

   // loop through the array 
   for (int i = 0; i < vectorSize; i++) {
      // 20. if the current value is equal to the valueInQuestion, 
      // return true, as the valueInQuestion is present in the array 
      if (theVector[i] == valueInQuestion) {
         return true; 
      }
   }

   // valueInQuestion is not in the array
   return false; 
}