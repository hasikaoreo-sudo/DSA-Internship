#include <iostream>
using namespace std;

class HashMap {
private:
    static const int SIZE = 10;

    int keys[SIZE];
    int values[SIZE];
    bool occupied[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
    }

    void display() {
        cout << "HashMap:" << endl;

        for (int i = 0; i < SIZE; i++) {
            if (occupied[i]) {
                cout << "Key: " << keys[i]
                     << " -> Value: " << values[i] << endl;
            }
        }
    }
};

int main() {
    HashMap map;

    map.insert(1, 100);
    map.insert(2, 200);
    map.insert(3, 300);
    map.insert(4, 400);

    map.display();

    return 0;
}
