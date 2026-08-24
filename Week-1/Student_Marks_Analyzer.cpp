#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "===== Student Marks Analyzer =====" << endl;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of students must be greater than 0." << endl;
        return 0;
    }

    int marks[n];

    // Input marks
    cout << "Enter marks for " << n << " students:" << endl;

    for (int i = 0; i < n; i++) {
        do {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Please enter marks between 0 and 100." << endl;
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    // Calculate total
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += marks[i];
    }

    double average = static_cast<double>(total) / n;

    // Sort marks in descending order using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    // Display sorted marks
    cout << "\nSorted marks (highest to lowest): ";

    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }

    cout << endl;

    // Display top 3 marks
    cout << "\n===== Top Marks =====" << endl;

    int topCount = (n < 3) ? n : 3;

    for (int i = 0; i < topCount; i++) {
        cout << "Rank " << i + 1 << ": " << marks[i] << endl;
    }

    // Display average
    cout << fixed << setprecision(2);
    cout << "\nAverage Score: " << average << endl;

    return 0;
}
