#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* left;
    Contact* right;
};

Contact* createContact(string name, string phone) {
    Contact* newContact = new Contact;

    newContact->name = name;
    newContact->phone = phone;
    newContact->left = nullptr;
    newContact->right = nullptr;

    return newContact;
}

Contact* insert(Contact* root, string name, string phone) {
    if (root == nullptr) {
        return createContact(name, phone);
    }

    if (name < root->name) {
        root->left = insert(root->left, name, phone);
    }
    else if (name > root->name) {
        root->right = insert(root->right, name, phone);
    }

    return root;
}

Contact* search(Contact* root, string name) {
    if (root == nullptr || root->name == name) {
        return root;
    }

    if (name < root->name) {
        return search(root->left, name);
    }

    return search(root->right, name);
}

Contact* findMinimum(Contact* root) {
    Contact* current = root;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

Contact* deleteContact(Contact* root, string name) {
    if (root == nullptr) {
        return root;
    }

    if (name < root->name) {
        root->left = deleteContact(root->left, name);
    }
    else if (name > root->name) {
        root->right = deleteContact(root->right, name);
    }
    else {
        // No left child
        if (root->left == nullptr) {
            Contact* temp = root->right;
            delete root;
            return temp;
        }

        // No right child
        if (root->right == nullptr) {
            Contact* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Contact* temp = findMinimum(root->right);

        root->name = temp->name;
        root->phone = temp->phone;

        root->right = deleteContact(root->right, temp->name);
    }

    return root;
}

void inorder(Contact* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << "Name: " << root->name
         << " | Phone: " << root->phone << endl;

    inorder(root->right);
}

int main() {
    Contact* root = nullptr;

    root = insert(root, "Rahul", "9876543210");
    root = insert(root, "Anu", "9876501234");
    root = insert(root, "Kiran", "9123456780");
    root = insert(root, "Priya", "9988776655");
    root = insert(root, "Arun", "9090909090");

    cout << "Contacts in Alphabetical Order:" << endl;
    inorder(root);

    string name;

    cout << "\nEnter name to search: ";
    cin >> name;

    Contact* result = search(root, name);

    if (result != nullptr) {
        cout << "Contact Found!" << endl;
        cout << "Name: " << result->name << endl;
        cout << "Phone: " << result->phone << endl;
    }
    else {
        cout << "Contact not found!" << endl;
    }

    cout << "\nEnter name to delete: ";
    cin >> name;

    if (search(root, name) != nullptr) {
        root = deleteContact(root, name);
        cout << "Contact deleted successfully!" << endl;
    }
    else {
        cout << "Contact not found!" << endl;
    }

    cout << "\nContacts after deletion:" << endl;
    inorder(root);

    return 0;
}
