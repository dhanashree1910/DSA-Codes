/* Implement Bubble sort using Doubly Linked List */

#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node*next;
    Node*prev;
    Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};
void insert_end(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void BubbleSort(Node*head){
    if(head == nullptr){
        return;
    }
    bool swapped ;
    Node*last = nullptr;

    do{
        swapped = false;
        Node*temp = head;
        while(temp->next != last){
            if(temp->value > temp->next->value){
                int t = temp->value;
                temp->value = temp->next->value;
                temp->next->value = t;
                swapped = true;
            }
            temp = temp->next;
        }

        last = temp;

    }while(swapped);
}

void display(Node*head){
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert_end(head, 40);
    insert_end(head, 10);
    insert_end(head, 50);
    insert_end(head, 20);
    insert_end(head, 30);

    cout << "Before Sorting:" << endl;
    display(head);

    BubbleSort(head);

    cout << "After Bubble Sort:" << endl;
    display(head);

    return 0;
}