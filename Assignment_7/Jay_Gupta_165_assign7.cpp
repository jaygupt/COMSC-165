#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// function prototypes 
vector<string> getVector(const string&);
string getName(const string&);
void selectionSort(vector<string>&);
bool search(const string&, const vector<string>&);
void displayResult(const string&, const string&, bool);
void writeToFile(const string& fileToCreate, const vector<string>& theVector);
void reverseVector(vector<string>& vectorToReverse);

int main() {
   string boyName, girlName;   
   bool boyNameFound, girlNameFound;  

   // 1. Declare and initialize vectors, by calling the getVector function, 
   // converting input from text files into vector values. 
   vector<string> boyNames(getVector("BoyNames.txt"));
   vector<string> girlNames(getVector("GirlNames.txt"));
   
   // whitespace before program 
   cout << endl; 

   // 2. Prompt user for name of boy and girl name; store choice in respective variable.
   boyName = getName("boy's");   
   girlName = getName("girl's");

   cout << endl; 

   // 3. if user selected N for boyName, display specific message, 
   // else, display if chosen name is popular or not. 
   if (boyName == "N") {
      cout << "You chose not to enter a boy's name." << endl; 
   } else {
      boyNameFound = search(boyName, boyNames);
      displayResult("boy's", boyName, boyNameFound);
   }

   // repeat with girl names
   if (girlName == "N") {
      cout << "You chose not to enter a girl's name." << endl; 
   } else {
      girlNameFound = search(girlName, girlNames);
      displayResult("girl's", girlName, girlNameFound);
   }

   // whitespace after the output of the program ends 
   cout << endl; 
   
   selectionSort(boyNames);  
   selectionSort(girlNames);
   
   writeToFile("Boynames_asc.txt", boyNames); 
   writeToFile("Girlnames_asc.txt", girlNames);

   reverseVector(boyNames); 
   reverseVector(girlNames);

   writeToFile("Boynames_desc.txt", boyNames); 
   writeToFile("Girlnames_desc.txt", girlNames);
   
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

// 4. getVector takes in a fileName as a parameter, and returns a 
// vector of the respective file's values 
vector<string> getVector(const string& fileName) {
   // 5. declare the ifstream object; ifstream because reading from fileName
   ifstream theFile(fileName); 

   // declare vector to be used 
   vector<string> theVector; 

   // 6. each data string from the file will be stored in name 
   string name; 

   // 7. while the program hasn't reached the end of the file, 
   // take a name and add it to theVector 
   while (theFile >> name) {
      theVector.push_back(name); 
   }

   // close the file  
   theFile.close(); 

   return theVector; 
}

// 8. getName takes in the gender, and asks the user for 
// a name of that gender that they think may be popular 
string getName(const string& gender) {
   // name to be returned
   string name; 

   cout << "Enter a " << gender << " name, or N if you do not wish "
   << "to enter a " << gender << " name: "; 
   cin >> name; 

   return name; 
}

// 9. searches vectorToSearch for name. If the name is there, returns 
// true; else, returns false 
bool search(const string& name, const vector<string>& vectorToSearch) {
   // 10. Uses a linear search; if the current value in the loop 
   // equals name, it will return true as the value is present in the vector 
   for (int i = 0; i < vectorToSearch.size(); i++) {
      if (name == vectorToSearch[i]) {
         return true; 
      }
   }

   return false; 
}

void displayResult(const string& gender, const string& name, bool nameFound) {
   // 11. if search returns true, print name is popular
   // else, print name isn't popular 

   if (nameFound) {
      cout << name << " is one of the most popular " << gender << " names."; 
   } else {
      cout << name << " is NOT one of the most popular " << gender << " names."; 
   }

   cout << endl; 
}

void reverseVector(vector<string>& vectorToReverse) {
   int vectorSize = vectorToReverse.size(); 

   // 12. going from the initial value up until just before the halfway 
   // value, store the current in temp, and set the current equal to 
   // its counterpart on the other side. 
   for (int i = 0; i < (vectorSize / 2); i++) {
      string temp = vectorToReverse[i];  
      vectorToReverse[i] = vectorToReverse[vectorSize - i - 1]; 
      vectorToReverse[vectorSize - i - 1] = temp; 
   }
}

void writeToFile(const string& fileToCreate, const vector<string>& theVector) {
   // 13. declare ofstream object, since we will be writing 
   // values to the file 
   ofstream outputFile(fileToCreate); 

   string name; 
   // 14. For each value in theVector, set the value to name, and 
   // write name along with an end line to outputFile
   for (int i = 0; i < theVector.size(); i++) {
      name = theVector[i]; 
      outputFile << name << endl; 
   }
}