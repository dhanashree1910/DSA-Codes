/*
In a call center, customer calls are handled on a first-come, first-served basis. Implement a queue system using Linked list where:
●	Each customer call is enqueued as it arrives.
●	Customer service agents dequeue calls to assist customers.
●	If there are no calls, the system waits.

*/

#include<iostream>
using namespace std;
class Node{
    public:
    string customerName;
    Node*next;
    Node(string v){
        customerName=v;
        next=nullptr;
    }
};

class Queue{
    public:
    Node*head;
    Node*tail;
    int size;
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void enqueue(string v){
        Node* newNode = new Node(v);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;        
    }
    void dequeue(){
        if (head == nullptr) {
            cout << "No calls in queue. Waiting for customer calls..." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp; // Correct way to free memory
    
        if (head == nullptr) { 
            tail = nullptr; // queue became empty
        }

        size--;
        cout << "Customer call attended and removed from queue." << endl;
    }
    bool isEmpty(){
        return head==nullptr;

    }
    string getFront(){
        if(head==nullptr) return "";
        return head->customerName;

    }

    void display(){
        if (isEmpty()) {
            cout << "No customer calls in queue." << endl;
            return;
        
        }

        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->customerName<<" ";
            temp=temp->next;
        }
        cout <<endl;
    }
};

int main(){
    Queue* q1 = new Queue();
    cout<<"1: Enqueue Customer"<<endl;
    cout<<"2: Dequeue Customer"<<endl;
    cout<<"3: Display Customers"<<endl;
    cout<<"4: Exit"<<endl;
    int choice;

    string name; // Declare outside switch to avoid bypassing initialization
    while(true){
    cout<<"Enter Choice:";
    cin>>choice;    
        switch (choice)
        {
        case 1:
            cout<<"Enter Name:";
            cin>>name;
            q1->enqueue(name);
            break;
        case 2:
            q1->dequeue();
            break;
        
        case 3: 
            q1->display();
            break;
            
        case 4:
            cout<<"Exiting..";
            return 0;    
        
        default:
            break;
        }
    }
}