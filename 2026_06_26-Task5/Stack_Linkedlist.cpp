#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string value) {
        name = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    bool isFull() {
        Node* temp = new(nothrow) Node("");
        if (temp == NULL)
            return true;

        delete temp;
        return false;
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = top;
        cout << temp->name << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << top->name << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << " Stack :" << endl;

        Node* current = top;
        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    Stack s;

    s.push("Aimar");
    s.push("Ahmad");
    s.push("Anajana");
    s.push("Jessy");

    cout << endl;
    s.display();

    cout << endl;
    s.peek();

    cout << endl;
    s.pop();

    cout << endl;
    s.display();

    cout << endl;
    s.peek();

    return 0;
}