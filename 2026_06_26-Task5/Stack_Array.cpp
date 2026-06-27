#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    static const int MAX = 5;  
    string arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack :" << endl;

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
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