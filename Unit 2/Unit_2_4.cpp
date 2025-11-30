/*4)  Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records. 
The Department of Computer Engineering has a student club named ‘Vertex Club’ for    
second, third, and final year students. The first member is the President and the last 
member is the Secretary. Write a C++ program to: 
● Add/delete members (including President/Secretary) 
● Count members 
● Display members 
● Concatenate two division lists 
Also implement: reverse, search by PRN, and sort by PRN operations.*/

#include <iostream>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;

    Node(int p, string n) {
        prn = p;
        name = n;
        next = nullptr;
    }
};

class VertexClub {
public:
    Node* head;

    VertexClub() {
        head = nullptr;
    }

    // ---------------- Add President (Insert at head) ----------------
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
    }

    // ---------------- Add Secretary (Insert at end) ----------------
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // ---------------- Add Member (Insert in middle) ----------------
    void addMember(int prn, string name, int pos) {
        if (pos == 1) {
            addPresident(prn, name);
            return;
        }

        Node* newNode = new Node(prn, name);
        Node* temp = head;
        int i = 1;

        while (i < pos - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ---------------- Delete President ----------------
    void deletePresident() {
        if (head == nullptr) {
            cout << "List empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // ---------------- Delete Secretary ----------------
    void deleteSecretary() {
        if (head == nullptr) {
            cout << "List empty!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // ---------------- Delete Member at given position ----------------
    void deleteMember(int pos) {
        if (pos == 1) {
            deletePresident();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // ---------------- Display ----------------
    void display() {
        if (head == nullptr) {
            cout << "List empty\n";
            return;
        }

        cout << "\nVERTEX CLUB MEMBERS:\n";
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->prn << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    // ---------------- Count Members ----------------
    int countMembers() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // ---------------- Search by PRN ----------------
    void search(int p) {
        Node* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->prn == p) {
                cout << "Found at position " << pos << ": " << temp->name << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found!\n";
    }

    // ---------------- Reverse ----------------
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // ---------------- Sort by PRN ----------------
    void sortByPRN() {
        if (head == nullptr) return;

        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->prn > j->prn) {
                    swap(i->prn, j->prn);
                    swap(i->name, j->name);
                }
            }
        }
    }

    // ---------------- Concatenate Two Lists ----------------
    void concatenate(VertexClub &other) {
        if (head == nullptr) {
            head = other.head;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = other.head;
    }
};


// ---------------- MAIN ----------------
int main() {
    VertexClub divA, divB;

    divA.addPresident(1, "Amit");
    divA.addSecretary(5, "Rahul");
    divA.addMember(3, "Sneha", 2);
    divA.addMember(4, "Sana", 3);

    cout << "Division A:\n";
    divA.display();

    cout << "\nTotal: " << divA.countMembers() << endl;

    cout << "\nSearch PRN 3:\n";
    divA.search(3);

    cout << "\nAfter Sorting:\n";
    divA.sortByPRN();
    divA.display();

    cout << "\nAfter Reversing:\n";
    divA.reverse();
    divA.display();

    divB.addPresident(10, "Pranav");
    divB.addSecretary(12, "Kiran");

    cout << "\nConcatenating Div A + Div B:\n";
    divA.concatenate(divB);
    divA.display();

    return 0;
}
