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

   vector<string> boyNames(getVector("BoyNames.txt"));
   vector<string> girlNames(getVector("GirlNames.txt"));
   
   // whitespace before program 
   cout << endl; 

   boyName = getName("boy's");   
   girlName = getName("girl's");

   cout << endl; 

   // if user selected N for boyName
   if (boyName == "N") {
      cout << "You chose not to enter a boy's name." << endl; 
   } else {
      boyNameFound = search(boyName, boyNames);
      displayResult("boy's", boyName, boyNameFound);
   }

   if (girlName == "N") {
      cout << "You chose not to enter a girl's name." << endl; 
   } else {
      girlNameFound = search(girlName, girlNames);
      displayResult("girl's", girlName, girlNameFound);
   }

   // whitespace after the program ends 
   cout << endl; 

   // test for getName
   // cout << "You selected: " << boyName << " for boy's name." << endl; 
   // cout << "You selected: " << girlName << " for girl's name." << endl;
   
   // selectionSort(boyNames);  
   // selectionSort(girlNames);
 

   // tests search function
   // if (boyNameFound) {
   //    cout << boyName << " was found in the boyNames vector."; 
   // } else {
   //    cout << boyName << " wasn't found in the boyNames vector.";
   // }

   // cout << endl; 

   // if (girlNameFound) {
   //    cout << girlName << " was found in the girlNames vector."; 
   // } else {
   //    cout << girlName << " wasn't found in the girlNames vector.";
   // }
       
   
   // writeToFile("Boynames_asc.txt", boyNames); 
   // writeToFile("Girlnames_asc.txt", girlNames);
   
   // reverseVector(boyNames); 
   // reverseVector(girlNames);

   // writeToFile("Boynames_desc.txt", boyNames); 
   // writeToFile("Girlnames_desc.txt", girlNames);
   
   // cout << endl;
   
   // system("PAUSE");
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
      theVector.push_back(name); 
   }

   // close the file to utilize processing power 
   theFile.close(); 

   return theVector; 
}

string getName(const string& gender) {
   // name to be returned
   string name; 

   cout << "Enter a " << gender << " name, or N if you do not wish "
   << "to enter a " << gender << " name: "; 
   cin >> name; 

   return name; 
}

// searches vectorToSearch for name
bool search(const string& name, const vector<string>& vectorToSearch) {
   for (int i = 0; i < vectorToSearch.size(); i++) {
      if (name == vectorToSearch[i]) {
         return true; 
      }
   }

   return false; 
}

void displayResult(const string& gender, const string& name, bool nameFound) {
   // if search returns true, print name is popular
   // else, print name isn't popular 

   if (nameFound) {
      cout << name << " is one of the most popular " << gender << " names."; 
   } else {
      cout << name << " is NOT one of the most popular " << gender << " names."; 
   }

   cout << endl; 
}