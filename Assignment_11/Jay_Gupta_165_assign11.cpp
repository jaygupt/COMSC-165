#include <iostream>
#include <string>
using namespace std; 

struct Drink {
    string name; 
    double cost; 
    int numOfDrink; 
}; 

int main() {
    // initialize structure objects to be put into array
    Drink cola = {"Cola", 0.75, 20};  
    Drink rootBeer = {"Root Beer", 0.75, 20}; 
    Drink lemonLime = {"Lemon-Lime", 0.75, 20}; 
    Drink grapeSoda = {"Grape Soda", 0.8, 20}; 
    Drink creamSoda = {"Cream Soda", 0.8, 20}; 

    struct Drink drinkArray[] = {cola, rootBeer, lemonLime, grapeSoda, creamSoda}; 

    cout << drinkArray[1].name << endl; 

    return 0; 
}