#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void read_file_into_vector(vector<string> &theVector, string fileName); 
void displayTeams(const vector<string> &teamsVector); 

int main() {
    vector<string> teams; 
    read_file_into_vector(teams, "Teams.txt"); 
    cout << "The following teams have won the world series at least once: " 
    << endl << endl; 
    displayTeams(teams); 
    return 0; 
}

void read_file_into_vector(vector<string> &theVector, string fileName) {
    ifstream theFile(fileName); 

    string currentLine; 

    while (getline(theFile, currentLine)) { 
        theVector.push_back(currentLine); 
    }

    theFile.close(); 
}

void displayTeams(const vector<string> &teamsVector) {
    for (int i = 0; i < teamsVector.size(); i++) {
        cout << teamsVector[i] << endl; 
    }
}