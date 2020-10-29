#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

// function prototypes 
void read_file_into_vector(vector<string> &theVector, string fileName); 
void displayTeams(const vector<string> &teamsVector); 
string promptUserForTeam(); 
int worldSeriesCounter(const vector<string> &winnerVector, string teamToCheckFor); 
void displayWinCount(string teamChosen, int teamWinCount); 

int main() {
    // variable declarations 
    string userTeam; 
    vector<string> teams;
    vector<string> winners; 
    int userTeamWinCount; 

    // 1. Read Teams.txt and Winners.txt into the vectors 
    // team and winners, respectively
    read_file_into_vector(teams, "Teams.txt"); 
    read_file_into_vector(winners, "Winners.txt"); 
    
    // 2. Display the teams that have won championships to the user
    displayTeams(teams); 

    // 3. Get the user's selected team, and use that info 
    // along with the winners vector to count how many times that 
    // team won the world series 
    userTeam = promptUserForTeam(); 
    userTeamWinCount = worldSeriesCounter(winners, userTeam); 

    // 4. Finally, display this count in a message 
    displayWinCount(userTeam, userTeamWinCount); 

    return 0; 
}

void read_file_into_vector(vector<string> &theVector, string fileName) {
    // declare ifstream object for reading file 
    ifstream theFile(fileName); 

    string currentLine; 

    // 5. While the end of the file hasn't been reached yet, 
    // get the next line. 
    while (!theFile.eof()) { 
        getline(theFile, currentLine); 

        // 6. If there is another line after the current. 
        if (!theFile.eof()) {
            // not at end of file yet; have to remove \n
            theVector.push_back(currentLine.substr(0, currentLine.length() - 1)); 
        } else {
            // 7. We are at end of file; the last line doesn't have a \n
            theVector.push_back(currentLine); 
        }
    }

    // close the file object 
    theFile.close(); 
}

void displayTeams(const vector<string> &teamsVector) {
    // 8. display the teams that have won using a for loop; 
    // we aren't changing the array, only reading; hence, use const 
    cout << "The following teams have won the world series at least once: " 
    << endl << endl; 
    for (int i = 0; i < teamsVector.size(); i++) {
        cout << teamsVector[i] << endl; 
    }
}

string promptUserForTeam() {
    // 9. Get the name of a team from the user. This team name
    // can have spaces, which is why getline is used instead of cin
    string userTeam; 

    cout << endl << "Enter the name of one of the teams: "; 
 
    getline(cin, userTeam); 

    return userTeam; 
}

int worldSeriesCounter(const vector<string> &winnerVector, string teamToCheckFor) {
    int occurrences = 0; 

    cout << "Team to Check for: " << teamToCheckFor << endl; 

    // 10. While looping through the array, if the teamToCheckFor occurs, 
    // increment the occurrences variable. 
    for (int i = 0; i < winnerVector.size(); i++) {
        if (winnerVector[i] == teamToCheckFor) {
            occurrences++; 
        }
    }

    return occurrences; 
}

void displayWinCount(string teamChosen, int teamWinCount) {
    // 11. Display the result to the user, using the variables 
    // teamChosen and teamWinCount
    cout << "The " << teamChosen << " have won the World Series " 
    << teamWinCount << " times between 1903 and 2012." << endl; 
}