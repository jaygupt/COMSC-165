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
    
    // compare who came first, second, or third
    string firstPerson; 
    string secondPerson; 
    string thirdPerson; 

    // determine who came first, second, and third: only 6 possible scenarios
    /*
    1. A, B, C
    2. A, C, B
    3. B, A, C
    4. B, C, A
    5. C, A, B
    6. C, B, A
    */

    if (runnerOneTime < runnerTwoTime && runnerTwoTime < runnerThreeTime) {
        firstPerson = runnerOneName; 
        secondPerson = runnerTwoName; 
        thirdPerson = runnerThreeName; 
    } else if (runnerOneTime < runnerThreeTime && runnerThreeTime < runnerTwoTime) {
        firstPerson = runnerOneName; 
        secondPerson = runnerThreeName; 
        thirdPerson = runnerTwoName; 
    } else if (runnerTwoTime < runnerOneTime && runnerOneTime < runnerThreeTime) {
        firstPerson = runnerTwoName; 
        secondPerson = runnerOneName; 
        thirdPerson = runnerThreeName; 
    } else if (runnerTwoTime < runnerThreeTime && runnerThreeTime < runnerOneTime) {
        firstPerson = runnerTwoName; 
        secondPerson = runnerThreeName; 
        thirdPerson = runnerOneName; 
    } else if (runnerThreeTime < runnerOneTime && runnerOneTime < runnerTwoTime) {
        firstPerson = runnerThreeName; 
        secondPerson = runnerOneName; 
        thirdPerson = runnerTwoName; 
    } else if (runnerThreeTime < runnerTwoTime && runnerTwoTime < runnerOneTime) {
        firstPerson = runnerThreeName; 
        secondPerson = runnerTwoName; 
        thirdPerson = runnerOneName; 
    } else {
        cout << "Error. You may have made two or more values equal to each other." << endl; 
    }

    cout << firstPerson << " came in 1st place." << endl; 
    cout << secondPerson << " came in 2nd place." << endl;
    cout << thirdPerson << " came in 3rd place." << endl;

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
    do {
        cout << "Runner " << runnerNum << "'s finishing time: "; 
        cin >> runnerTime;
        if (runnerTime < 0) {
            cout << "Enter positive values only for each runner's time." << endl;
        }
    } while (runnerTime < 0); 
    cin.ignore(256, '\n');
    return runnerTime; 
}