// 1. Including a header file for input/output functions
#include <iostream>
#include <string>
using namespace std; 

// 2. function prototypes; this allows me to place my functions in any order I choose 
string promptName(int runnerNum);
double promptTime(int runnerNum); 

int main() {
    // 2. Introductory statement to user, telling them what the program will be about.
    cout << "Enter the names of three runners and their " << 
    "finishing times. I will tell you who came in first, " <<
    "second, and third." << endl; 

    // Get Runner 1's name and time 
    string runnerOneName = promptName(1); 
    double runnerOneTime = promptTime(1);

    // Get Runner 2's name and time 
    string runnerTwoName = promptName(2); 
    double runnerTwoTime = promptTime(2); 

    // Get Runner 3's name and time 
    string runnerThreeName = promptName(3); 
    double runnerThreeTime = promptTime(3); 

    // error checking; are any of the times less than 0? 
    if (runnerOneTime < 0 || runnerTwoTime < 0 || runnerThreeTime < 0) {
        cout << "Enter positive values only for each runner's time."; 
        return -1; 
    }

    return 0; 
}

string promptName(int runnerNum) { 
    char runnerName[50]; 
    cout << "Name of Runner " << runnerNum << ": "; 
    cin.getline(runnerName, 50); 
    return runnerName; 
}

double promptTime(int runnerNum) {
    double runnerTime; 
    cout << "Runner " << runnerNum << "'s finishing time: "; 
    cin >> runnerTime;  
    cin.ignore(256, '\n');
    return runnerTime; 
}