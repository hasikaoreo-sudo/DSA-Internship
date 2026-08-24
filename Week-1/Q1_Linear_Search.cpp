#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int position = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        cout << "Element found at index: " << position << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
