// Chapter 12, Programming Challenge 13: Inventory Program
#include <iostream>
#include <fstream>
using namespace std;

// Constant for array sizes
const int DESC_SIZE = 31;
const int DATE_SIZE = 11;

// Declaration of Inventory structure

// each Inventory object needs to take up the EXACT same amount of bytes in the file
// so we need to AVOID using type string, and use character arrays with fixed sizes 
// instead. Note that the size of each character array represents the MAXIMUM
// amount of characters that can be stored, but we can choose to store less characters
// (bytes) than the maximum
struct Inventory {
   char desc[DESC_SIZE];  // Description
   int qty;               // Quantity
   double wholeSale;      // Wholesale Cost
   double retail;         // Retail price
   char date[DATE_SIZE];  // Date Added to Inventory

   Inventory* next = nullptr; // Only the printList and buildList
                              // functions use the next pointer
                              // So when every Inventory object is
                              // created, it's next pointer is
                              // initialized to nullptr
};

// Function Prototypes
// each function receives an fstream object by reference
// remember that we can use fstream objects for BOTH reading and writing from/to files
void addRecord(fstream &);
void viewRecord(fstream &invFile, const int recordNumber);
void changeRecord(fstream &invFile); 

int main() {
   // File stream object
   fstream inventoryFile;

   // 1. Record number is used as a 
   // parameter in the viewRecord function.
   int recordNumber;
   
   // User's menu choice
   int choice;
   
   // Display the menu and process the
   // user's request.
   do {
      // Display the menu.
      cout << "\n1. Add a new record\n";
      cout << "2. View an existing record\n";
      cout << "3. Change an existing record\n";
      cout << "4. Exit\n\n";

      // Get the user's menu selection.
      cout << "Enter your choice (1-4): ";
      cin >> choice;
      
      // Validate the menu selection.
      while (choice < 1 || choice > 4)
      {
         cout << "ERROR. Enter 1, 2, 3, or 4: ";
         cin >> choice;
      }
   
      // Process the selection.
      switch (choice)
      {
         // 2. If the user selects 1, call the addRecord function,
         // and pass in the inventoryFile fstream object.
         case 1:  
            addRecord(inventoryFile);
            break;
         // 3. If the user selects 2, first prompt the user for the 
         // record number they want to view, and pass this number into
         // the viewRecord function, along with the inventoryFile 
         // fstream object.
         case 2:
            cout << endl << "Enter the record number of the item: "; 
            cin >> recordNumber; 
            viewRecord(inventoryFile, recordNumber); 
            break; 
         // 4. If the user selects 3, call the changeRecord function,
         // and pass in the inventoryFile fstream object.
         case 3:
            changeRecord(inventoryFile); 
            break;
         // 5. If the user selects 4, the do-while loop will end. 
         case 4:
            break;  
     }
   } while (choice != 4);

   // TODO: Implement rest of main here.

   return 0;
}

//************************************************
// Function addRecord                            *
// This function gets the data for a record      *
// and writes it to the file.                    *
//************************************************

// this function works with the file in append mode, since we need to add new 
// records to the end of the file, and we don't want to lose any of the records
// that we have previously added to the file.
void addRecord(fstream &invFile) {
   // An inventory structure to hold an
   // inventory record.
   Inventory record;

   // Open the file.
   invFile.open("invtry.dat", ios::out | ios::app | ios::binary);
   
   // If an error happens, exit.

   // fail returns true if there was an error with trying to open the file
   // otherwise fail returns false if the file could be opened

   // the exit function will terminate the entire program
   if (invFile.fail())
   {
      cout << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }

   cin.get(); // make sure that the keyboard buffer is empty 
              // before prompting the user for the description

   cout << "\nEnter the following inventory data:\n";
   
   // Get the description.
   cout << "Description: ";

   // we are using cin.getline rather than getline, since the desc field is a 
   // character array (rather than a string)
   // the first argument here to cin.getline is the name of the char array, and
   // the second is it's size

   cin.getline(record.desc, DESC_SIZE);
   
   // Get the quantity.
   cout << "Quantity: ";
   cin >> record.qty;
   while (record.qty < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.qty;
   }

   // Get the wholesale cost.
   cout << "Wholesale Cost: ";
   cin >> record.wholeSale;
   while (record.wholeSale < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.wholeSale;
   }
   
   // Get the retail price.
   cout << "Retail price: ";
   cin >> record.retail;
   while (record.retail < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.retail;
   }
   
   // Get the date added to inventory.
   cout << "Date Added to Inventory: ";
   cin >> record.date;

   // NOTE: The user does not enter a value for the next field
   // But it's important to keep in mind that the write statement
   // below writes the four bytes for the next field
   // to the binary file
   // Since every Inventory object has it's next field
   // initialized to nullptr, this means that address 0
   // is written to the binary file

   // Write the record.
   // Note that we don't need to call seekp before this write.
   // Since we opened the file in append mode, it will already write
   // to the end of the file and not overwrite any of the data that is already
   // in the file.
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
   
   // Make sure we didn't have an error writing.
   if (invFile.fail())
      cout << "Error writing record to file.\n";
   else
      cout << "Record written to file.\n";
      
   // Close the file.
   invFile.close();
}

void viewRecord(fstream &invFile, const int recordNumber) {
   // to hold inventory record
   Inventory record; 

   // 6. Open the file in input mode, since nothing is going to
   // be written, rather, there will only be reading from the file.
   invFile.open("invtry.dat", ios::in | ios::binary);

   // 7. Ensure that the file opened. The exit function 
   // will terminate the entire program if it didn't. 
   if (invFile.fail())
   {
      cout << endl << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }

   // 8. Use seekg to go to offset in file for reading. 
   // To find this offset, we are multiplying the user given 
   // recordNumber by the size of a maximum Inventory object.  
   invFile.seekg(recordNumber * sizeof(Inventory), ios::beg); 

   // 9. Once at the correct position, read the file 
   // information into the record variable.  
   invFile.read(reinterpret_cast<char *>(&record), sizeof(record));

   // 10. Display the data for the user to see. 
   cout << "Description: " << record.desc << endl; 
   cout << "Quantity: " << record.qty << endl; 
   cout << "Wholesale Cost: " << record.wholeSale << endl;
   cout << "Retail price: " << record.retail << endl; 
   cout << "Date Added to Inventory: " << record.date << endl;

   // close the file 
   invFile.close(); 
}

void changeRecord(fstream &invFile) {
   // to hold inventory record
   Inventory record; 
   
   int recordNumber; 

   // 11. Get record number in order to pass to viewRecord
   // function and display the current data to the user. 
   cout << endl << "Enter the record number of the item: "; 
   cin >> recordNumber; 

   // display current contents
   cout << endl << "Current record contents: " << endl; 
   viewRecord(invFile, recordNumber);

   // 12. Open file in output mode only, as there will 
   // only be writing to the file.  
   invFile.open("invtry.dat", ios::out | ios::binary);

   cout << endl << "Enter the new data: " << endl; 

   // 13. Using .get() to ensure that buffer is cleared before 
   // prompting for description. 
   cin.get();

   cout << "Description: "; 
   cin.getline(record.desc, DESC_SIZE); 

   cout << "Quantity: "; 
   cin >> record.qty; 
   while (record.qty < 0) {
      cout << "Enter a positive value, please: ";
      cin >> record.qty;
   }

   cout << "Wholesale Cost: "; 
   cin >> record.wholeSale; 
   while (record.wholeSale < 0) {
      cout << "Enter a positive value, please: ";
      cin >> record.wholeSale;
   }

   cout << "Retail price: "; 
   cin >> record.retail; 
   while (record.retail < 0) {
      cout << "Enter a positive value, please: ";
      cin >> record.retail;
   }

   cout << "Date Added to Inventory: "; 
   cin >> record.date; 

   // 14. Using seekp, go to offset using recordNumber in 
   // order to get to correct position.
   invFile.seekp(recordNumber * sizeof(Inventory), ios::beg);

   // overwrite original record using write. 
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));

   // ensure no errors with writing
   if (invFile.fail())
      cout << "Error changing record.\n";
   else
      cout << "Record has been changed.\n";

   // close file
   invFile.close(); 
}