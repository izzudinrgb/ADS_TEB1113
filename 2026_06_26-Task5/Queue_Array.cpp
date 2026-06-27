#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int MAX = 5;
    string arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void push(string value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        rear++;
        arr[rear] = value;

        cout << value << " pushed into queue." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " popped from queue." << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue :" << endl;

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
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