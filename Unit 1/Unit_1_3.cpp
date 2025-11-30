/*Write a program using Bubble sort algorithm, assign the roll nos. to the students of 
your class as per their previous years result. i.e. topper will be roll no. 1 and analyse 
the sorting algorithm pass by pass.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[50];
    string names[50];

    // Input student names and marks
    for(int i = 0; i < n; i++) {
        cout << "Enter name of student " << i+1 << ": ";
        cin >> names[i];
        cout << "Enter marks: ";
        cin >> marks[i];
    }

    // Bubble Sort (Descending order)
    for(int pass = 1; pass < n; pass++) {
        cout << "\nPass " << pass << ":\n";

        for(int i = 0; i < n - pass; i++) {
            if(marks[i] < marks[i+1]) {
                // swap marks
                int temp = marks[i];
                marks[i] = marks[i+1];
                marks[i+1] = temp;

                // swap names also
                string t = names[i];
                names[i] = names[i+1];
                names[i+1] = t;
            }
        }

        // Print array after each pass
        for(int i = 0; i < n; i++) {
            cout << names[i] << " (" << marks[i] << ")\n";
        }
    }

    // Final roll numbers
    cout << "\nFinal Roll Numbers (Topper = Roll No. 1):\n";
    for(int i = 0; i < n; i++) {
        cout << "Roll " << i+1 << ": " << names[i]
             << " - Marks: " << marks[i] << endl;
    }

    return 0;
}
