#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertFront(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    void search(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            if (current->name == name) {
                cout << name << " found in the list." << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << name << " not found." << endl;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            if (current->name == name) {

                if (current->next == head && current->prev == head) {
                    delete current;
                    head = nullptr;
                    return;
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head) {
                    head = head->next;
                }

                delete current;
                cout << name << " deleted." << endl;
                return;
            }

            current = current->next;

        } while (current != head);

        cout << name << " not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head->prev;

        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);
    }
};

int main() {

    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    cout << "\nAfter inserting Ali at the front:" << endl;
    list.insertFront("Ali");
    list.display();

    cout << "\nSearch result:" << endl;
    list.search("Jessy");
    list.search("Jane");

    cout << "\nAfter deleting Anjana:" << endl;
    list.deleteByName("Anjana");
    list.display();

    cout << "\nReverse list:" << endl;
    list.displayReverse();

    return 0;
}