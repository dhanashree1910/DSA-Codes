/*1) WAP to perform addition of two polynomials using singly linked list. */
#include<iostream>
using namespace std;

struct Node{
    int coeff;
    int power;
    Node*next; //pointer to the next term
};

Node* createNode(int c,int p){
    Node* temp = new Node;
    temp->coeff=c;
    temp->power=p;
    temp->next=NULL;
    return temp;
}

void insertNode(Node*&head , int c , int p){
    if(head==NULL){
        head = createNode(c,p);
        return ;
    }
    Node*temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }//now temp is pointing the last node
    Node*newNode = createNode(c,p);
    temp->next = newNode;

    return;
}

Node* addPolynomial(Node*head1, Node*head2){
    Node*temp1 = head1;
    Node*temp2 = head2;
    Node*result = NULL;
    
    while(temp1 && temp2){
        if(temp1->power==temp2->power){
            insertNode(result,temp1->coeff+temp2->coeff,temp1->power);
            temp1= temp1->next;
            temp2= temp2->next;
        }
        else if(temp1->power > temp2->power){
            insertNode(result,temp1->coeff,temp1->power);
            temp1=temp1->next;
        }
        else{
            insertNode(result,temp2->coeff,temp2->power);
            temp2=temp2->next;
        }
    }

    if(temp1!=NULL){
        while(temp1){
            insertNode(result,temp1->coeff,temp1->power);
            temp1= temp1->next;
        }
    }
    if(temp2!=NULL){
        while(temp2){
            insertNode(result,temp2->coeff,temp2->power);
            temp2= temp2->next;
        }
    }

    return result;
}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->coeff << "x^" << temp->power;
        if(temp->next) cout << " + ";
        temp = temp->next;
    }
}

int main(){
    Node* head1 = createNode(2,3);
    insertNode(head1,3,2);
    insertNode(head1,4,1);
    insertNode(head1,2,0);

    Node*head2 = createNode(8,4);
    insertNode(head2,6,2);
    insertNode(head2,2,0);
    
    Node* head3 = addPolynomial(head1,head2);
    display(head3);
}