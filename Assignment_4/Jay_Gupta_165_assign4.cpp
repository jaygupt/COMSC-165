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

    // primary instructions to the user 
    displayInstructions(); 

    getUserInput(studentAnswers, answerKeySize); 

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
        cout << "Question " << i + 1 << ": "; 
        cin >> userInput; 
        // input validation: if userInput is not A, B, C, or D, re-prompt the user until 
        // they input one of the correct options. 
        while (userInput != 'A' && userInput != 'B' && userInput != 'C' && userInput != 'D') {
            cout << "Use only an A, B, C, or D!" << endl; 
            cout << "Please try again: "; 
            cin >> userInput; 
        }
        arr[i] = userInput;  
    }

    cout << endl; 
}

void displayResults(const char studentAnswers[], const char answerKey[], 
    int answerKeySize, int incorrectAnswers[]) {
    // number of correct answers 
    int correct = 0; 
    for (int i = 0; i < answerKeySize; i++) {
        if (studentAnswers[i] != answerKey[i]) {
            // if the student's answer is incorrect

            // at the same place in the incorrectAnswers array,
            // store the question number 
            incorrectAnswers[i] = i + 1; 
        } else {
            // if the student's answer is correct
            correct++; 
        }
    }

    int incorrect = answerKeySize - correct; 

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
        if (arr[i] != 0) {
            cout << arr[i] << endl; 
        } 
    }
    cout << endl; 
}