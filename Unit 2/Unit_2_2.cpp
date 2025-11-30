/* WAP to create a doubly linked list and perform
   Insert (all cases) and Delete (all cases)
*/

#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// ---------------- INSERT AT START ----------------
void insert_at_start(Node*& head, int v){
    Node* newNode = new Node(v);

    if(head == nullptr){
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// ---------------- INSERT AT END ----------------
void insert_at_end(Node*& head, int v){
    Node* newNode = new Node(v);

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// ---------------- INSERT AT MID ----------------
void insert_at_mid(Node*& head, int v, int pos){
    if(pos < 1){
        cout << "Invalid Position!" << endl;
        return;
    }

    if(pos == 1){
        insert_at_start(head, v);
        return;
    }

    Node* temp = head;
    int i = 1;

    while(i < pos - 1 && temp){
        temp = temp->next;
        i++;
    }

    if(temp == nullptr){
        cout << "Position out of range!" << endl;
        return;
    }

    if(temp->next == nullptr){
        insert_at_end(head, v);
        return;
    }

    // Insert in middle
    Node* newNode = new Node(v);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// ---------------- DELETE AT START ----------------
void delete_at_start(Node*& head){
    if(head == nullptr){
        cout << "Nothing to delete" << endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

// ---------------- DELETE AT END ----------------
void delete_at_end(Node*& head){
    if(head == nullptr){
        cout << "Nothing to delete" << endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

// ---------------- DELETE AT MID ----------------
void delete_at_mid(Node*& head, int pos){
    if(head == nullptr){
        cout << "Nothing to delete" << endl;
        return;
    }

    if(pos == 1){
        delete_at_start(head);
        return;
    }

    int i = 1;
    Node* temp = head;

    while(i < pos && temp){
        temp = temp->next;
        i++;
    }

    if(temp == nullptr){
        cout << "Position out of range!" << endl;
        return;
    }

    if(temp->next == nullptr){
        delete_at_end(head);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// --------------- DISPLAY LIST ----------------
void display(Node* head){
    Node* temp = head;
    cout << "List : ";
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------------- MAIN ----------------
int main(){
    Node* head = nullptr;

    insert_at_start(head, 10);
    insert_at_end(head, 20);
    insert_at_end(head, 30);
    insert_at_mid(head, 15, 2);
    display(head);

    delete_at_mid(head, 2);
    display(head);

    delete_at_end(head);
    display(head);

    return 0;
}
