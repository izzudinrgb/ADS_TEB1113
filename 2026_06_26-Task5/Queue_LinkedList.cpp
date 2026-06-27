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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
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
            cout << "Queue Overflow!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " pushed into queue." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        cout << temp->name << " popped from queue." << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << front->name << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue :" << endl;

        Node* current = front;

        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue q;

    q.push("Aimar");
    q.push("Ahmad");
    q.push("Anajana");
    q.push("Jessy");

    cout << endl;
    q.display();

    cout << endl;
    q.peek();

    cout << endl;
    q.pop();

    cout << endl;
    q.display();

    cout << endl;
    q.peek();

    return 0;
}