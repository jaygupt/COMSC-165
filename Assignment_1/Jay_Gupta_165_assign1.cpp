// 1. Including a header file for input/output functions
#include <iostream>
using namespace std; 

// 2. function prototypes; this allows me to place my functions in any order I choose 
int promptName(int runnerNum); 
int promptTime(int runnerNum); 

int main() {
    // 2. Introductory statement to user, telling them what the program will be about.
    cout << "Enter the names of three runners and their " << 
    "finishing times. I will tell you who came in first, " <<
    "second, and third." << endl; 

    promptName(0); 
    promptTime(10); 

    return 0; 
}

int promptName(int runnerNum) {
    cout << "Name of Runner " << runnerNum << ": "; 
    return 7; 
}

int promptTime(int runnerNum) {
    cout << "Runner " << runnerNum << "'s finishing time: "; 
    return 3; 
}