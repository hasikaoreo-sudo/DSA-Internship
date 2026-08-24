#include <iostream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;

            if (index == originalIndex) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        table[index] = key;
    }

    void display() {
        cout << "Hash Table:" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(45);

    hashTable.display();

    return 0;
}
