#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string value) {
        name = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertEnd(string value) {
        Node* newNode = new Node(value);

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

    // Insert after a specific name
    void insertAfter(string target, string value) {
        Node* temp = head;

        while (temp != nullptr && temp->name != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Name not found!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by name
    void deleteByName(string value) {

        if (head == nullptr)
            return;

        if (head->name == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            if (current->next->name == value) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }

            current = current->next;
        }
    }

    // Display the linked list
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {

    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Ahmad");
    list.insertEnd("Anjana");

    cout << "Initial List:" << endl;
    list.display();

    // Insert Ali after Ahmad
    list.insertAfter("Ahmad", "Ali");

    // Delete Anjana
    list.deleteByName("Anjana");

    cout << "\nFinal List:" << endl;
    list.display();

    return 0;
}