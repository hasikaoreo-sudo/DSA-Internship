#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reverseUsingStack(Node*& head) {
    if (head == nullptr)
        return;

    stack<int> s;
    Node* temp = head;

    // Push all elements into stack
    while (temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }

    // Put elements back in reverse order
    temp = head;

    while (temp != nullptr) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Original Linked List: ";
    display(head);

    reverseUsingStack(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}
