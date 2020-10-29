#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void read_file_into_vector(vector<string> &theVector, string fileName); 
void displayTeams(const vector<string> &teamsVector); 
string promptUserForTeam(); 
int worldSeriesCounter(const vector<string> &winnerVector, string teamToCheckFor); 
void displayWinCount(string teamChosen, int teamWinCount); 

int main() {
    string userTeam; 
    vector<string> teams;
    vector<string> winners; 
    int userTeamWinCount; 

    read_file_into_vector(teams, "Teams.txt"); 
    read_file_into_vector(winners, "Winners.txt"); 
    
    displayTeams(teams); 

    userTeam = promptUserForTeam(); 
    userTeamWinCount = worldSeriesCounter(winners, userTeam); 

    displayWinCount(userTeam, userTeamWinCount); 

    return 0; 
}

void read_file_into_vector(vector<string> &theVector, string fileName) {
    ifstream theFile(fileName); 

    string currentLine; 

    while (!theFile.eof()) { 
        getline(theFile, currentLine); 

        if (!theFile.eof()) {
            // not at end of file yet; have to remove \n
            theVector.push_back(currentLine.substr(0, currentLine.length() - 1)); 
        } else {
            // at end of file 
            theVector.push_back(currentLine); 
        }
    }

    theFile.close(); 
}

void displayTeams(const vector<string> &teamsVector) {
    cout << "The following teams have won the world series at least once: " 
    << endl << endl; 
    for (int i = 0; i < teamsVector.size(); i++) {
        cout << teamsVector[i] << endl; 
    }
}

string promptUserForTeam() {
    string userTeam; 

    cout << endl << "Enter the name of one of the teams: "; 
 
    getline(cin, userTeam); 

    return userTeam; 
}

int worldSeriesCounter(const vector<string> &winnerVector, string teamToCheckFor) {
    int occurrences = 0; 

    cout << "Team to Check for: " << teamToCheckFor << endl; 

    for (int i = 0; i < winnerVector.size(); i++) {
        if (winnerVector.at(i).compare(teamToCheckFor) == 0) {
            occurrences++; 
        }
    }

    return occurrences; 
}

void displayWinCount(string teamChosen, int teamWinCount) {
    cout << "The " << teamChosen << " have won the World Series " 
    << teamWinCount << " times between 1903 and 2012." << endl; 
}