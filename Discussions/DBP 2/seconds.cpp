#include <windows.h> // for Sleep(milliseconds)
#include <iostream>
using namespace std; 

void printTime(int day, int hour, int minute, int second); 

int main() {
    // day 
    for (int day = 0; day <= 6; day++) {
         // hour 
        for (int hour = 0; hour <= 23; hour++) {
            // minute
            for (int minute = 0; minute <= 59; minute++) {
                // seconds 
                for (int second = 0; second <= 59; second++) {
                    printTime(day, hour, minute, second); 
                    // Sleep(1000); 
                }
            }
        }
    }

    cout << endl << "Number of seconds in a week: 604800" << endl; 
    return 0; 
}

void printTime(int day, int hour, int minute, int second) {
    cout << day << ":" << hour << ":" << minute << ":" << second << endl;
}