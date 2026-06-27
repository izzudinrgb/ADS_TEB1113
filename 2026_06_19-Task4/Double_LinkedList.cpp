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
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // insert at front
    void insertFront(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }


    void search(string name) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->name == name) {
                cout << name << " found in list." << endl;
                return;
            }
            temp = temp->next;
        }

        cout << name << " not found." << endl;
    }


    void deleteByName(string name) {
        if (head == NULL) return;

        Node* temp = head;

        while (temp != NULL && temp->name != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << name << " not found." << endl;
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != NULL) head->prev = NULL;
        }
        else {
            temp->prev->next = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << name << " deleted." << endl;
    }

    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // go backwards
        while (temp != NULL) {
            cout << temp->name << endl;
            temp = temp->prev;
        }
    }
};

int main() {

    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    cout << "\nInsert front (Ali):" << endl;
    list.insertFront("Ali");
    list.display();

    cout << "\nSearch Jessy:" << endl;
    list.search("Jessy");

    cout << "\nDelete Anjana:" << endl;
    list.deleteByName("Anjana");
    list.display();

    cout << "\nReverse display:" << endl;
    list.displayReverse();

    return 0;
}