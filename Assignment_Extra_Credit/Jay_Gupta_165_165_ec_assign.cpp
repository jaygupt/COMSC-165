#include <iostream>
using namespace std; 

// specified structure 
struct LinkedList {
    int value; 
    LinkedList* next; // singly-linked list 
}; 

// function prototypes
int getNumOfNodes(); 
void append_node(LinkedList* &head, int givenValue); 
void display_list(const LinkedList* head, const string status); 
void insert_node(LinkedList* &head, const int index, const int givenValue); 
void delete_node(LinkedList* &head, int givenValue); 
int search_node(const LinkedList* head, int givenValue); 
void destroy_list(LinkedList* &head); 

int main() {
    // 1. Head set to nullptr initially
    LinkedList* head = nullptr;  

    // variables
    int givenValue; // holds user values
    int insertIndex; // passed to insert_node

    // 2. numOfNodes will hold the number of specified nodes
    int numOfNodes = getNumOfNodes(); 

    // for each node:
    for (int i = 0; i < numOfNodes; i++) {
        // 3. The user enters a number, and it is stored in givenValue
        cout << "Enter a number: "; 
        cin >> givenValue;

        // 4. givenValue is passed to the append_node function
        // by value, to create that new node
        append_node(head, givenValue); 
    } 

    // 5. As this is the main function, we are getting user input
    // and passing those values to the individual functions
    display_list(head, "initial"); 

    cout << "Enter the value of the node to be inserted: ";
    cin >> givenValue; 

    cout << "Enter the index for this new node (index starts at 0): "; 
    cin >> insertIndex; 

    insert_node(head, insertIndex, givenValue); 

    display_list(head, "updated"); 

    cout << "Enter the value of the node to be deleted: "; 
    cin >> givenValue; 

    delete_node(head, givenValue); 

    display_list(head, "updated"); 

    cout << "Enter the value of the node you want to search for: "; 
    cin >> givenValue;

    int indexOfValue = search_node(head, givenValue); 

    cout << endl << "The value \"" << givenValue << "\" was found at index " 
    << indexOfValue << " in the linked list." << endl << endl; 

    destroy_list(head); 

    return 0; 
}

int getNumOfNodes() {
    int userInput; 
    bool validInput = false;

    cout << endl;  

    do {
        cout << "Enter the number of initial nodes (must be at least 1): ";
        cin >> userInput; 

        // 6. Until userInput is greater than or equal to 1 (meaning non-negative and 
        // at least 1), the loop won't be broken
        if (userInput >= 1) {
            validInput = true; 
        }
    } while (!validInput);

    cout << endl; 

    return userInput;  
}

void append_node(LinkedList* &head, int givenValue) {
    // 7. Create a new node by using the "new" operator
    // and using givenValue. Since this will be the last
    // node in the list (after function is executed), 
    // next property will be set to nullptr. 
    LinkedList* new_node = new LinkedList; 
    new_node->value = givenValue;
    new_node->next = nullptr;  

    // 8. if head points to nullptr, the list is empty. 
    if (head == nullptr) {
        // if it is, set head to new_node 
        head = new_node; 
    } else {
        // 9. Else, head doesn't point to nullptr,
        // and the list is not empty

        // 10. ptr will be used to traverse the list, as 
        // using head directly makes you lose starting address  
        LinkedList* ptr = head;

        // 11. the last node in the list has a next property of nullptr
        while (ptr->next != nullptr) {
            // 12. keep on going to the next node until we reach the last one
            ptr = ptr->next; 
        }

        // 13. set the last node's next property to new_node, 
        // completing append functionality 
        ptr->next = new_node; 
    }
}

void display_list(const LinkedList* head, const string status) {
    // 14. ptr is constant due to principle of least priviledge
    const LinkedList* ptr = head; 

    cout << endl; 

    // 15. since the wording is used multiple times throughout 
    // program, used a conditional. 
    if (status == "initial") {
        cout << "Here is the initial linked list:"; 
    } else {
        cout << "Here is the updated linked list:"; 
    }

    cout << endl; 

    // 16. until ptr reaches the end of the list, it will print
    // out each value from each node. 
    while (ptr != nullptr) {
        cout << ptr->value << endl; 
        ptr = ptr->next; 
    }

    cout << endl; 
}

void insert_node(LinkedList* &head, const int index, const int givenValue) {
    // create a new node
    LinkedList* new_node = new LinkedList; 
    new_node->value = givenValue;
    new_node->next = nullptr;  

    // pointer to previous node 
    LinkedList* prev = head;

    if (index == 0) {
        // 17. The user wants to insert at 0 index
        // new_node is put in place of head 
        new_node->next = head; 
        head = new_node; 
    } else {
        // anywhere else 
        for (int i = 0; i < (index - 1); i++) {
            if (prev->next == nullptr) {
                break; 
            } else {
                prev = prev->next; 
            }
        }

        new_node->next = prev->next; 
        prev->next = new_node; 
    }
}

void delete_node(LinkedList* &head, int givenValue) {
    LinkedList* ptr = head;
    LinkedList* prev = nullptr; 

    if (ptr->value == givenValue) {
        // head has the value

        // set head equal to the next node 
        head = ptr->next; 
    } else {
        while (ptr != nullptr && ptr->value != givenValue) {
            prev = ptr; 
            ptr = ptr->next; 
        } 

        prev->next = ptr->next; 
    }

    delete ptr; 
    ptr = nullptr; 
}

int search_node(const LinkedList* head, int givenValue) {
    const LinkedList* ptr = head;
    int indexOfValue = 0; 

    // 18. when the givenValue is found, the loop breaks
    while (ptr != nullptr) {
        if (ptr->value == givenValue) {
            break;  
        }

        ptr = ptr->next; 
        indexOfValue++; 
    }

    return indexOfValue; 
}

void destroy_list(LinkedList* &head) {
    LinkedList* ptr = head; 

    // if the list only has one value
    if (ptr->next == nullptr) {
        delete ptr; 
    } else {
        // more than one value 

        LinkedList* prev = nullptr; 

        // 19. Works by having a prev and a ptr; 
        // prev is deleted each time.
        while (ptr->next != nullptr) {
            prev = ptr; 
            ptr = ptr->next; 

            delete prev; 
        }

        delete ptr; 
        prev = nullptr; 
    }

    // 20. Set ptr and head to nullptr, to not leave
    // them dangling.
    ptr = nullptr; 
    head = nullptr; 
}