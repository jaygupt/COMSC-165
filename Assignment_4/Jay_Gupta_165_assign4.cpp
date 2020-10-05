#include <iostream>
#include <iomanip>
using namespace std; 

// function prototypes 
void displayIncorrectAnswers(const int arr[], int arraySize); 
void displayInstructions(); 
void getUserInput(char arr[], int arraySize); 
void displayResults(const char studentAnswers[], const char answerKey[], 
    int answerKeySize, int incorrectAnswers[]); 

int main() {
    // 1. Set the size of every array used in this program; all are dependent on the 
    // answer key array 
    const int answerKeySize = 20;

    // initialize arrays 
    char answerKey[answerKeySize] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 
    'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'}; 
    char studentAnswers[answerKeySize] = {}; 
    int incorrectAnswers[answerKeySize] = {}; 

    // 2. Display primary instructions to the user 
    displayInstructions(); 

    // 3. Get the user input, and store it in the studentAnswers array 
    getUserInput(studentAnswers, answerKeySize); 

    // 4. Display the results: pass or fail, number of correct and incorrect, and 
    // the specific questions that were answered incorrectly 
    displayResults(studentAnswers, answerKey, answerKeySize, incorrectAnswers);  
    return 0; 
}

void displayInstructions() {
    cout << endl << "Please enter the student's answers for each of the questions." << endl; 
    cout << "Press Enter after typing each answer." << endl; 
    cout << "Please enter only an A, B, C, or D for each question." << endl << endl; 
}

void getUserInput(char arr[], int arraySize) {
    char userInput; 
    for (int i = 0; i < arraySize; i++) {
        // display the question prompt 
        cout << "Question " << i + 1 << ": "; 
        cin >> userInput; 

        // 5. input validation: if userInput is not A, B, C, or D, re-prompt the user until 
        // they input one of the correct options. 
        while (userInput != 'A' && userInput != 'B' && userInput != 'C' && userInput != 'D') {
            cout << "Use only an A, B, C, or D!" << endl; 
            cout << "Please try again: "; 
            cin >> userInput; 
        }

        // 6. Set the array (studentAnswers) at that particular index to 
        // the user's input 
        arr[i] = userInput;  
    }

    cout << endl; 
}

// 7. Since studentAnswers and answerKey are being read, and not changed, set them
// to const. However, incorrectAnswers will be updated; don't include the const keyword. 
void displayResults(const char studentAnswers[], const char answerKey[], 
    int answerKeySize, int incorrectAnswers[]) {
    // number of correct answers 
    int correct = 0; 

    // 8. Compare both arrays, to determine the number correct, and 
    // to form the incorrectAnswers array 
    for (int i = 0; i < answerKeySize; i++) {
        if (studentAnswers[i] != answerKey[i]) {
            // if the student's answer is incorrect

            // 9. at the same place in the incorrectAnswers array,
            // store the question number
            incorrectAnswers[i] = i + 1; 
        } else {
            // if the student's answer is correct
            correct++; 
        }
    }

    // 10. The number of incorrect answers is the total number of questions - the number correct
    int incorrect = answerKeySize - correct; 

    // 11. Display if the user passed or failed the exam
    // based on number of correct
    if (correct >= 15) {
        cout << "The student passed the exam." << endl; 
    } else {
        cout << "The student failed the exam." << endl; 
    }

    cout << endl << "Correct Answers: " << correct << endl; 
    cout << "Incorrect Answers: " << incorrect << endl << endl; 
    
    cout << "Questions that were answered incorrectly:" << endl; 
    displayIncorrectAnswers(incorrectAnswers, answerKeySize);
    cout << "----------------------------" << endl; 
}

void displayIncorrectAnswers(const int arr[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        // 12. If the value is not equal to 0, that means 
        // the user got that question number wrong, and it needs to 
        // be printed out in the "Questions that were asked incorrectly" section
        if (arr[i] != 0) {
            cout << arr[i] << endl; 
        } 
    }
    cout << endl; 
}