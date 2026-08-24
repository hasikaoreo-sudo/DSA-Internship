#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    // Remove the top element
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow." << endl;
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack." << endl;

        top = top->next;
        delete temp;
    }

    // Display the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;

        cout << "Stack (top to bottom): ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    Stack stack;

    int n;

    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        stack.push(value);
    }

    stack.display();

    stack.pop();

    stack.display();

    return 0;
}
