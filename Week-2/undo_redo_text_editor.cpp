#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string newText) {
        undoStack.push(text);
        text += newText;

        // Clear redo stack after a new action
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }

        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }

        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
    }

    void display() {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello ");
    editor.display();

    editor.type("World");
    editor.display();

    editor.undo();
    cout << "After Undo: ";
    editor.display();

    editor.redo();
    cout << "After Redo: ";
    editor.display();

    editor.type("!");
    cout << "After New Action: ";
    editor.display();

    editor.undo();
    cout << "After Undo: ";
    editor.display();

    return 0;
}
