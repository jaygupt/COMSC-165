// 1. Including an iostream for input/output functions and 
// string for the string data type. 
#include <iostream>
#include <string>
using namespace std; 

// 2. Function prototypes; it allows me to place my functions 
// in any order I choose. 
string promptName(int runnerNum);
double promptTime(int runnerNum); 

int main() {
    // 3. Introductory statement to user, telling them what the program 
    // will do for them.
    cout << endl << "Enter the names of three runners and their " << 
    "finishing times." << endl << "I will tell you who came in first, " <<
    "second, and third." << endl; 

    // 4a. Get Runner 1's name and time. 
    string runnerOneName = promptName(1); 
    double runnerOneTime = promptTime(1);

    // 4b. Get Runner 2's name and time. 
    string runnerTwoName = promptName(2); 
    double runnerTwoTime = promptTime(2); 

    // 4c. Get Runner 3's name and time. 
    string runnerThreeName = promptName(3); 
    double runnerThreeTime = promptTime(3); 
    
    // 5. This section compares the runners to see 
    // who came first, second, and third.
    string firstPerson; 
    string secondPerson; 
    string thirdPerson; 

    // 6. There are only 6 possible combinations of 
    // who came first, second, or third. 
    /*
    1. A, B, C
    2. A, C, B
    3. B, A, C
    4. B, C, A
    5. C, A, B
    6. C, B, A
    */

    // 7. Using above combinations to determine the case type, and 
    // attributing firstPerson, secondPerson, and thirdPerson accordingly. 
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
        // 8. This will only show if two or more numbers are equal 
        // to each other. 
        cout << "Error. You may have made two or more values equal to each other." << endl; 
    }

    // 9. Display results based on comparisons. 
    cout << endl << firstPerson << " came in 1st place." << endl; 
    cout << secondPerson << " came in 2nd place." << endl;
    cout << thirdPerson << " came in 3rd place." << endl << endl;

    return 0; 
}

// 10. This function asks for the name of the runner, 
// taking in their runner number for output purposes.
string promptName(int runnerNum) { 
    char runnerName[50]; 
    cout << endl << "Name of Runner " << runnerNum << ": ";

    // 11. Using .getline as opposed to cin because cin 
    // doesn't allow strings with spaces in between them. 
    cin.getline(runnerName, 50); 
    
    return runnerName; 
}

// 12. This function asks for the runner's time,
// taking in their runner number for output purposes. 
double promptTime(int runnerNum) {
    double runnerTime; 
    do {
        cout << "Runner " << runnerNum << "'s finishing time: "; 
        cin >> runnerTime;

        // 13. If runnerTime is negative, an error message will display, 
        // and the user must enter a valid number in order to proceed. 
        if (runnerTime < 0) {
            cout << endl << "Enter positive values only for each runner's time." << endl << endl;
        }
    } while (runnerTime < 0); 

    // 14. .ignore is used due to issues with the input buffer; 
    // namely, when the user presses the enter key, it carries over 
    // to the next runner's name input, not allowing them to 
    // enter in a value. 
    cin.ignore(256, '\n');

    return runnerTime; 
}