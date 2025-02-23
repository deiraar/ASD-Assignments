// Name: Deira Aisya Refani
// NIM: 24/532821/PA/22539
// Class: CSA

#include <iostream>
using namespace std;

class Node {
    public:
        int iData;
        Node* next;
        Node* prev;

        // Constructor to initialize data and pointers
        Node(int data) {
            iData = data;
            next = nullptr;
            prev = nullptr;
        }
};

class DoubleLinkedList {
    private:
        Node* head;
        Node* tail;
    
    public:
        // Constructor to initialize the head and tail to null
        DoubleLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // Method to check if the list is empty
        bool isEmpty() {
            return head == nullptr;
        }

        // 1. Adding new node at head for double linked list
        void addFront(int data) {
            Node* newNode = new Node(data); // Create a new node
            if (isEmpty()) {
                head = newNode;
                tail = newNode;  // If list is empty, both head and tail point to new node
            }
            else {
                newNode->next = head; // Set the new node's next to the current head
                head->prev = newNode; // Update the previous pointer of the current head
                head = newNode; // Update the head to the new node
            }
        }

        // 2. Adding new node at tail for double linked list
        void addBack(int data) {
            Node* newNode = new Node(data); // Create a new node
            if (isEmpty()) {
                head = newNode;
                tail = newNode;  // If list is empty, both head and tail point to new node
            }
            else {
                tail->next = newNode; // Set the current tail's next to the new node
                newNode->prev = tail; // Set the new node's previous pointer to the current tail
                tail = newNode; // Update the tail to the new node
            }
        }

        // 3. Adding new node at the middle for double linked list
        void addMiddle(int data) {
            Node* newNode = new Node(data); // Create a new node
            if (isEmpty()) {
                head = newNode;
                tail = newNode;  // If list is empty, both head and tail point to new node
            }
            else {
                int size = 0;
                Node* current = head;

                // Calculate the size of the list
                while (current != nullptr) {
                    size++;
                    current = current->next;
                }

                // Find the middle position
                int middlePos = size / 2;

                // Traverse to the middle node
                current = head;
                for (int i = 1; i < middlePos; i++) {
                    current = current->next;
                }

                // Insert the new node after the middle node
                newNode->next = current->next;  // Set the new node's next to the current middle's next
                if (current->next != nullptr) {
                    current->next->prev = newNode;  // Update the next node's prev pointer
                }
                current->next = newNode;  // Set the current middle's next to the new node
                newNode->prev = current;  // Set the new node's prev to the current middle

                // If the new node is added at the end, update the tail
                if (current == tail) {
                    tail = newNode;
                }
            }
        }

        // 4. Removing node at head for double linked list
        void removeFront() {
            if (!isEmpty()) {
                Node* temp = head;
                head = head->next; // Update the head to the next node
                if (head != nullptr) {
                    head->prev = nullptr; // Set the new head's previous pointer to null
                }
                else {
                    tail = nullptr; // If list becomes empty, update tail to null
                }
                delete temp; // Delete the old head
            }
            else {
                cout << "List is empty, nothing to delete!" << endl;
            }
        }

        // 5. Removing node at tail for double linked list
        void removeBack() {
            if (!isEmpty()) {
                Node* temp = tail;
                tail = tail->prev; // Update the tail to the previous node
                if (tail != nullptr) {
                    tail->next = nullptr; // Set the new tail's next pointer to null
                }
                else {
                    head = nullptr; // If list becomes empty, update head to null
                }
                delete temp; // Delete the old head
            }
            else {
                cout << "List is empty, nothing to delete!" << endl;
            }
        }

        // 6. Removing node at the middle for double linked list
        void removeMiddle() {
            if (isEmpty()) {
                cout << "List is empty, nothing to remove!" << endl;
                return;
            }
    
            int size = 0;
            Node* current = head;
    
            // Calculate the size of the list
            while (current != nullptr) {
                size++;
                current = current->next;
            }
    
            if (size == 1) {
                // If the list has only one node, remove it
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
    
            // Find the middle position
            int middlePos = size / 2;
    
            // Traverse to the middle node
            current = head;
            for (int i = 0; i < middlePos; i++) {
                current = current->next;
            }
    
            // Remove the middle node
            if (current->prev != nullptr) {
                current->prev->next = current->next;  // Update the previous node's next pointer
            } else {
                head = current->next;  // If the middle node is the head, update head to the next node
            }
    
            if (current->next != nullptr) {
                current->next->prev = current->prev;  // Update the next node's prev pointer
            } else {
                tail = current->prev;  // If the middle node is the tail, update tail to the previous node
            }
    
            delete current;  // Delete the middle node
        }

    // Getter method to access the head node
    Node* getHead() {
        return head;
    }
};

int main() {
    DoubleLinkedList list;
    
    list.addFront(1);
    list.addFront(2);
    list.addBack(5);
    list.addBack(6);
    list.addMiddle(3);
    list.addMiddle(4);

    cout << "List after adding elements at front, back and middle: ";
    Node* current = list.getHead();
    while (current != nullptr) {
        cout << current->iData << " ";
        current = current->next;
    }
    cout << endl;

    list.removeFront();
    list.removeBack();
    list.removeMiddle();

    cout << "List after removing elements at front, back and middle: ";
    current = list.getHead();
    while (current != nullptr) {
        cout << current->iData << " ";
        current = current->next;
    }
    cout << endl; 
}
