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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete first occurrence of a value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted." << endl;
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " not found." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << value << " deleted." << endl;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        cout << "Linked List: ";

        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    int n;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        list.insert(value);
    }

    list.display();

    int deleteValue;

    cout << "Enter value to delete: ";
    cin >> deleteValue;

    list.deleteNode(deleteValue);

    list.display();

    return 0;
}
