#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

// 1. Drink structure, as specified in program specification.
struct Drink {
    // 2. name and cost are const as they never change.
    const string name; 
    const double cost;
    // 3. numOfDrink, on the other hand, changes throughout
    // the program. Hence, it is a non-const.  
    int numOfDrink; 
}; 

// 4. function prototypes. Depending on the nature of the function,
// parameters are either constant or not. 
void displayDrinks(const Drink drinkArray[], const int arraySize); 
int getUserChoice(const Drink drinkArray[]); 
double enterMoney(Drink drinkArray[], const int userChoice); 
double calculateChange(double moneyEntered, const Drink drinkArray[], const int userChoice); 

int main() {
    // 5. will be outputted later to show how much machine made. 
    double moneyEarned; 

    // 6. initialize structure objects to be put into array
    Drink cola = {"Cola", 0.75, 20};  
    Drink rootBeer = {"Root Beer", 0.75, 20}; 
    Drink lemonLime = {"Lemon-Lime", 0.75, 20}; 
    Drink grapeSoda = {"Grape Soda", 0.8, 20}; 
    Drink creamSoda = {"Cream Soda", 0.8, 20}; 

    // 7. create the drink array based on the structure objects
    Drink drinkArray[] = {cola, rootBeer, lemonLime, grapeSoda, creamSoda}; 

    // 8. find size of array. As always, since this isn't built in,
    // have to do it using the size of the entire array,
    // divided by an individual element.
    int sizeOfArray = sizeof(drinkArray) / sizeof(drinkArray[0]); 

    // 9. For any output showing money, we will use 2 decimal places.
    cout << fixed; 
    cout << setprecision(2); 

    // main loop
    while (true) {
        // 10. display available drinks. The function
        // doesn't return anything.
        displayDrinks(drinkArray, sizeOfArray); 

        // 11. Get the user's choice. 
        int userChoice = getUserChoice(drinkArray);  

        // 12. If userChoice is 6, the user wants to exit.
        // Therefore, break the loop. 
        if (userChoice == 6) {
            break; 
        }

        // 13. enterMoney ensures that user pays right amount,
        // between the cost of the drink and a dollar.
        
        // 14. Additionally, the function returns 
        // moneyEntered in order to calculate change.
        double moneyEntered = enterMoney(drinkArray, userChoice); 
       
        // 15. Add the cost of the drink to moneyEarned. Change
        // not included, only net income. 
        moneyEarned += drinkArray[userChoice - 1].cost; 
        
        // 16. Calculate change, and display it. 
        double change = calculateChange(moneyEntered, drinkArray, userChoice); 
 
        cout << endl << "Change calculated: $" << change << endl; 

        // 17. Display stock situation of the drink that the user chose.
        cout << "There are " << drinkArray[userChoice - 1].numOfDrink << " drinks of that type left." << endl; 
    }

    // 18. Output total earnings made by the machine. 
    cout << endl << "Total Earnings: $" << moneyEarned << endl << endl; 
    
    return 0; 
}

// 19. displayDrinks function. Since it isn't changing the array, 
// drinkArray is const; same with arraySize. 
void displayDrinks(const Drink drinkArray[], const int arraySize) {
    cout << endl; 

    // 20. Create a loop to display all of the drinks and information. 
    for (int i = 0; i < arraySize; i++) {
        string drinkName = drinkArray[i].name; 
        double drinkCost = drinkArray[i].cost; 

        // 21. printf is used to space output accordingly.
        printf("%-1d) %-20s $%-4.2f\n", (i + 1), drinkName.c_str(), drinkCost); 
    }

    // print last option
    cout << "6) Leave the drink machine" << endl << endl; 
}

int getUserChoice(const Drink drinkArray[]) {
    int userChoice; 
    bool validInput = false; 

    cout << "Choose one: "; 
    cin >> userChoice; 

    do {
        // 22. Doing a few checks here. First and foremost, 
        // check to see if userChoice is between 1 and 6.
        if (userChoice < 1 || userChoice > 6) {
            cout << "Choose a selection between 1 and 6: "; 
            cin >> userChoice;
        } else if (userChoice >= 1 && userChoice <= 5) {
            // 23. If userChoice is in between 1 and 5 (drink options), 
            // check to see the drink they want is in stock.
            int quantityLeft = drinkArray[userChoice - 1].numOfDrink; 

            // 24. If the drink is out of stock, let user know, and 
            // ask them to choose again.
            if (quantityLeft == 0) {
                cout << "Sorry, that drink is out of stock. Please pick another option: ";
                cin >> userChoice;  
            } else {
                validInput = true; 
            }
        } else if (userChoice == 6) {
            // 25. Finally, if the user selects 6, this is valid input.
            // they will exit the program once checked in main.
            validInput = true; 
        }
    } while (!validInput); 

    return userChoice; 
}

double enterMoney(Drink drinkArray[], const int userChoice) { 
    double drinkPrice = drinkArray[userChoice - 1].cost;  
    double userInput; 
    bool validInput = false; 

    cout << endl << "Enter an amount of money: $";
    cin >> userInput; 

    do {
        // 26. Check the userInput. If it isn't between the 
        // price of the drink and 1 dollar, output accordinly.
        if (userInput < drinkPrice || userInput > 1) {
            cout << fixed; 
            cout << setprecision(2); 
            cout << "Enter at least $" << drinkPrice << " and not more than 1 dollar: $"; 
            cin >> userInput;  
        } else {
            validInput = true; 

            // 27. Once the user has paid, decrement numOfDrink of
            // the type that the user chose. 
            drinkArray[userChoice - 1].numOfDrink--; 
        }
    } while (!validInput); 

    cout << endl << "Enjoy your beverage!" << endl; 

    return userInput; 
}

double calculateChange(double moneyEntered, const Drink drinkArray[], const int userChoice) {
    // 28. Calculate change by taking the moneyEntered 
    // and subtracting the price of the drink. Return to 
    // main for output purposes. 
    double drinkPrice = drinkArray[userChoice - 1].cost;
    double change = moneyEntered - drinkPrice; 

    return change; 
}