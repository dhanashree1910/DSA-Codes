/*WAP to simulate a faculty database as a hash table. Search a particular faculty by 
using MOD as a hash function for linear probing with chaining with replacement 
method of collision handling technique. Assume suitable data for faculty record*/
#include <iostream>
#include <string>
using namespace std;

struct Faculty {
    int id;
    string name;
    string dept;
    bool occupied;

    Faculty() {
        id = -1;
        name = "";
        dept = "";
        occupied = false;
    }
};

class HashTable {
    int size;
    Faculty* table;

public:
    HashTable(int s) {
        size = s;
        table = new Faculty[size];
    }

    int hashFunction(int key) {
        return key % size;
    }

    // Insert using Linear Probing + Chaining with Replacement
    void insertFaculty(int id, string name, string dept) {
        int index = hashFunction(id);

        // If slot empty → directly insert
        if (!table[index].occupied) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;
            return;
        }

        // If slot occupied but the existing element DOES NOT belong here → REPLACEMENT
        int existingIndex = hashFunction(table[index].id);

        if (existingIndex != index) {
            // Replacement occurs
            Faculty temp = table[index];  // store old record

            // Put new record in correct hash location
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;

            // Reinsert displaced element using linear probing
            insertFaculty(temp.id, temp.name, temp.dept);
            return;
        }

        // Otherwise, normal linear probing
        int i = (index + 1) % size;
        while (i != index) {
            if (!table[i].occupied) {
                table[i].id = id;
                table[i].name = name;
                table[i].dept = dept;
                table[i].occupied = true;
                return;
            }
            i = (i + 1) % size;
        }

        cout << "Hash Table Full! Cannot insert.\n";
    }

    // Search by faculty ID
    void searchFaculty(int id) {
        int index = hashFunction(id);

        int i = index;
        while (table[i].occupied) {
            if (table[i].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[i].id << endl;
                cout << "Name: " << table[i].name << endl;
                cout << "Department: " << table[i].dept << endl;
                return;
            }
            i = (i + 1) % size;
            if (i == index) break;
        }

        cout << "\nFaculty with ID " << id << " not found!\n";
    }

    void displayTable() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < size; i++) {
            if (table[i].occupied) {
                cout << i << " -> " << table[i].id << " | "
                     << table[i].name << " | " << table[i].dept << endl;
            }
            else {
                cout << i << " -> empty\n";
            }
        }
    }
};

int main() {
    HashTable ht(10);

    // --- Sample Faculty Records ---
    ht.insertFaculty(101, "Dr. Amit", "Computer");
    ht.insertFaculty(205, "Dr. Neha", "ENTC");
    ht.insertFaculty(315, "Dr. Kiran", "Mechanical");
    ht.insertFaculty(109, "Dr. Riya", "Civil");
    ht.insertFaculty(503, "Dr. Meera", "IT");

    ht.displayTable();

    int sid;
    cout << "\nEnter Faculty ID to search: ";
    cin >> sid;

    ht.searchFaculty(sid);

    return 0;
}
