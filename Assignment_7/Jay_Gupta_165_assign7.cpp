#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> getVector(const string&);
string getName(const string&);
void selectionSort(vector<string>&);
bool search(const string&, const vector<string>&);
void displayResult(const string&, const string&, bool);
void writeToFile(const string&, const vector<string>&);
void reverseVector(vector<string>&);

int main() {
   string boyName, girlName;   
   bool boyNameFound, girlNameFound;  

   // vector<string> boyNames(getVector("BoyNames.txt"));
   // vector<string> girlNames(getVector("GirlNames.txt"));
   
   // boyName = getName("boy's");   
   // girlName = getName("girl's");
   
   // selectionSort(boyNames);  
   // selectionSort(girlNames);
   
   // boyNameFound = search(boyName, boyNames); 
   // girlNameFound = search(girlName, girlNames);
   
   // displayResult("boy's", boyName, boyNameFound);    
   // displayResult("girl's", girlName, girlNameFound);
   
   // writeToFile("Boynames_asc.txt", boyNames); 
   // writeToFile("Girlnames_asc.txt", girlNames);
   
   // reverseVector(boyNames); 
   // reverseVector(girlNames);

   // writeToFile("Boynames_desc.txt", boyNames); 
   // writeToFile("Girlnames_desc.txt", girlNames);
   
   // cout << endl;
   
   system("PAUSE");
   return 0;
}

void selectionSort(vector<string> &arr) {
	int startScan, minIndex;
	string minValue;

   for (startScan = 0; startScan < (arr.size() - 1); startScan++) {
      minIndex = startScan;
      minValue = arr[startScan];
      for(int index = startScan + 1; index < arr.size(); index++) {
         if (arr[index] < minValue) {
            minValue = arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = minValue;
   }
}

vector<string> getVector(const string& fileName) {
   // declare the ifstream object; reading from fileName
   ifstream theFile(fileName); 

   // declare vector to be used 
   vector<string> theVector; 

   // each data string from the file will be stored in name 
   string name; 

   // while the program hasn't reached the end of the file
   while (theFile >> name) {
      cout << name << endl; 
      theVector.push_back(name); 
   }

   // close the file to utilize processing power 
   theFile.close(); 

   return theVector; 
}

string getName(const string& gender) {
   // name to be returned
   string name = "Placeholder"; 

   cout << "Enter a " << gender << " name, or N if you do not wish "
   << "to enter a " << gender << " name"; 

   return name; 
}