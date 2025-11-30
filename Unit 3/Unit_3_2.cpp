/*Write a program to keep track of patients as they checked into
 a medical clinic, assigning patients to doctors on a first-come, 
 first-served basis.*/

#include<iostream>
#include<queue>
using namespace std;

void getPatients(queue<string> &n){
    int choice;
    while(true){
    cout<<"Do you want the next patients?"<<endl;
    cout<<"1:Next patient:"<<endl;
    cout<<"2:Exit"<<endl;
    cout<<"Enter:";
    cin>>choice;
    if(choice==1){
        if(n.empty()) {
            cout << "No more patients in the queue." << endl;
            break;
        } else {
            cout << "Next patient:" << n.front() << endl;
            n.pop();
        }
        
    }
      if(choice==2){
          break;
      }
    }
    
}
int main(){
    queue<string> patients;
    cout<<"Do you want to enter the patients?"<<endl;
        
    while(true){
        cout<<"1 : to enter the patients"<<endl;
        cout<<"2 : to exit"<<endl;
        cout<<"Enter:"<<endl;
        int choice;
        cin>>choice;
        if(choice == 1){
            string name;
            cout<<"Enter Name:"<<endl;
            cin>>name;
            patients.push(name);

        }
        if (choice == 2){
            break;
        }
    }
    getPatients(patients);
    return 0;

}