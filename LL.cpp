#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; // the data stored in the Node
    Node* next; // the pointer to the next Node
    
    Node(int value) { // Constructor to initialize the next Node
        data=value;
        next = nullptr; // Initialize pointer to null
    }
};

Node* head = nullptr;

void insertAtHead(int value) {
    // create new Node
    Node* newNode = new Node(value);
    // make new Node connected point to the current Head
    newNode->next = head;
    //connect the head to the new Node
    head = newNode;
}

void printList() {
    Node* temp = head;// use a temporary pointer to traverse the list
    cout <<"Linked List: ";
    while (temp!=nullptr) {
        cout <<temp->data << " -> ";
        temp=temp->next; // move to the next node
    }
    cout << "NULL" << endl;
}

void insertAtTheEnd (int value) {
    Node* newNode = new Node(value);
    if (head==nullptr) {
        head=newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    temp->next = newNode;
}

void deleteNode (int value) {
    if (head==nullptr) {
        cout << "The list is empty";
        return;
    }
    if (head->data=value) {
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    
    while (current!= nullptr and current->data!=value) {
        prev=current;
        current=current->next;
    }
    
    if (current==nullptr) {
        cout <<"Value " << value << " not found in the list" << endl;
        return;
    }
    
    prev->next=current->next;
    delete current;
}

void insertAfterNode(Node* prevNode, int value) {
    if (prevNode == nullptr) {
        cout << "Previous Node cannot be NULL";
        return;
    }
    
    Node* newNode = new Node(value);
    newNode->next = prevNode->next;
    prevNode->next=newNode;
}

void insertBeforeNode(Node* nextNode, int value) {
    if (nextNode == nullptr) {
        cout << "Next Node cannot be NULL";
        return;
    }
    
    if (nextNode == head) {
        insertAtHead(value);
        return;
    }
    
    Node* current = head;
    while (current!=nullptr and current->next!=nextNode){
        current->next;
    }
    if (current==nullptr) {
        cout << "Given Node is not in the list!";
        return;
    }
    
    Node* newNode = new Node(value);
    newNode->next = nextNode;
    current->next = newNode;
}

void insertAtPosition(int position, int value) {
    if (position < 0) {
        cout << "position cannot be less than 0";
        return;
    }
    if (position==0) {
        insertAtHead(value);
        return;
    }
    Node* current = head;
    for (int i=0; i<position-1 and current!=nullptr; i++) {
        current=current->next;
    }
    if (current==nullptr) {
        cout << "Position " << position << " is out of bounds!" << endl;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=current->next;
    current->next=newNode;
}

int main() {
    // Start with an empty list

    insertAtHead(3); // List: 3 -> NULL
    insertAtHead(2); // List: 2 -> 3 -> NULL
    insertAtHead(1); // List: 1 -> 2 -> 3 -> NULL
    
    insertAtPosition(3, 5);
    
    printList();
    
    deleteNode(1);
    
    printList();
    
    return 0;
}
