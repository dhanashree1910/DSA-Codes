/*WAP to build a simple stock price tracker that keeps a history of daily stock prices 
entered by the user. To allow users to go back and view or remove the most recent price, 
implement a stack using a linked list to store these integer prices. 
Implement the following operations: 
a. record(price) – Add a new stock price (an integer) to the stack. 
b. remove() – Remove and return the most recent price (top of the stack). 
c. latest() – Return the most recent stock price without removing it. 
d. isEmpty() – Check if there are no prices recorded. */

#include <iostream>
using namespace std;

// Node structure for linked list
class Node {
public:
    int price;
    Node* next;

    Node(int p) {
        price = p;
        next = nullptr;
    }
};

// Stack implemented using linked list
class StockStack {
public:
    Node* top;
    StockStack() {
        top = nullptr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Add a new stock price
    void record(int price) {
        Node* newNode = new Node(price);
        newNode->next = top;
        top = newNode;
        cout << "Price " << price << " recorded.\n";
    }

    // Remove the most recent price
    int remove() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to remove.\n";
            return -1; // or any sentinel value
        }
        int removedPrice = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;
        return removedPrice;
    }

    // Get the most recent price without removing
    int latest() {
        if (isEmpty()) {
            cout << "Stack is empty. No latest price.\n";
            return -1; // or any sentinel value
        }
        return top->price;
    }

    // Display all prices (optional, for testing)
    void display() {
        if (isEmpty()) {
            cout << "No prices recorded.\n";
            return;
        }
        Node* temp = top;
        cout << "Stock Price History (latest first): ";
        while (temp != nullptr) {
            cout << temp->price << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StockStack stockTracker;
    int choice, price;

    do {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record Price\n";
        cout << "2. Remove Latest Price\n";
        cout << "3. View Latest Price\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display All Prices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter stock price to record: ";
                cin >> price;
                stockTracker.record(price);
                break;
            case 2:
                price = stockTracker.remove();
                if (price != -1)
                    cout << "Removed price: " << price << endl;
                break;
            case 3:
                price = stockTracker.latest();
                if (price != -1)
                    cout << "Latest price: " << price << endl;
                break;
            case 4:
                if (stockTracker.isEmpty())
                    cout << "No prices recorded.\n";
                else
                    cout << "Prices are recorded.\n";
                break;
            case 5:
                stockTracker.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
