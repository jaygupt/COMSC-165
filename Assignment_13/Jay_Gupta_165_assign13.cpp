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
struct Inventory
{
   char desc[DESC_SIZE];  // Description
   int qty;               // Quantity
   double wholeSale;      // Wholesale cost
   double retail;         // Retail price
   char date[DATE_SIZE];  // Date added to inventory

   Inventory* next = nullptr; // Only the printList and buildList
                             // functions use the next pointer
                             // So when every Inventory object is
                             // created, it's next pointer is
                            // initialized to nullptr
};

// Function prototypes
// each function receives an fstream object by reference
// remember that we can use fstream objects for BOTH reading and writing from/to files
void addRecord(fstream &);

// --- ADD THE PROTOTYPES FOR THE REMAINING FOUR (4) FUNCTIONS ---
// --- ADD THE PROTOTYPES FOR THE REMAINING FOUR (4) FUNCTIONS ---
// --- ADD THE PROTOTYPES FOR THE REMAINING FOUR (4) FUNCTIONS ---
// --- ADD THE PROTOTYPES FOR THE REMAINING FOUR (4) FUNCTIONS ---
// --- ADD THE PROTOTYPES FOR THE REMAINING FOUR (4) FUNCTIONS ---

int main()
{
	Inventory inv;
    cout << inv.next;
   // File stream object
   fstream inventoryFile;
   
   // User's menu choice
   int choice;
   
   // Display the menu and process the
   // user's request.
   do
   {
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
         // Choice 1 is to add a record.
         case 1:  
            addRecord(inventoryFile);
            break;
     
     // --- IMPLEMENT THE REST OF THIS SWITCH STATEMENT ---
     // --- IMPLEMENT THE REST OF THIS SWITCH STATEMENT ---
     // --- IMPLEMENT THE REST OF THIS SWITCH STATEMENT ---
     // --- IMPLEMENT THE REST OF THIS SWITCH STATEMENT ---
     // --- IMPLEMENT THE REST OF THIS SWITCH STATEMENT ---
     
     }
     
   } while (choice != 4);


   // --- IMPLEMENT THE REST OF MAIN ---
   // --- IMPLEMENT THE REST OF MAIN ---
   // --- IMPLEMENT THE REST OF MAIN ---
   // --- IMPLEMENT THE REST OF MAIN ---
   // --- IMPLEMENT THE REST OF MAIN ---

 //  system("PAUSE");
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
void addRecord(fstream &invFile)
{
   // An inventory structure to hold an
   // inventory record.
   Inventory record;

   // Open the file.
   invFile.open("invtry.dat", ios::out | ios::app | ios::binary);

   
   // If an error happened, exit.

   // fail returns true if there was an error with trying to open the file
   // otherwise fail returns false if the file could be opened

   // the exit function will terminate the entire program
   if (invFile.fail())
   {
      cout << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }
   cin.get(); //make sure that the keyboard buffer is empty 
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
   cout << "Wholesale cost: ";
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
   cout << "Date added to inventory: ";
   cin >> record.date;

   // NOTE: The user does not enter a value for the next field
   // But it's important to keep in mind that the write statement
   // below writes the four bytes for the next field
   // to the binary file
   // Since every Inventory object has it's next field
   // initialized to nullptr, this means that address 0
   // is written to the binary file

   // Write the record.
   // Note that we don't need to calll seekp before this write.
   // Since we opened the file in append mode, it will already write
   // to the end of the file and not overwrite any of the data that is already
   // in the file.
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
   
   // Make sure we didn't have an error writing.
   if (invFile.fail())
      cout << "Error writing record to file.\n";
   else
      cout << "record written to file.\n\n";
      
   // Close the file.
   invFile.close();
}

// --- IMPLEMENT THE REMAINING FOUR (4) FUNCTIONS ---
// --- IMPLEMENT THE REMAINING FOUR (4) FUNCTIONS ---
// --- IMPLEMENT THE REMAINING FOUR (4) FUNCTIONS ---
// --- IMPLEMENT THE REMAINING FOUR (4) FUNCTIONS ---
// --- IMPLEMENT THE REMAINING FOUR (4) FUNCTIONS ---


