#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    Node(int val) {
        data = val;
    }
};

Node *head = NULL;
Node *tail = NULL;

void insertVal(int val) {
    Node * newnode = new Node(val);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        head->next = NULL;
        tail = head;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void printLL() {
    Node * curr = head;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

void reverse() {
    // 1 2 3 4
    Node *curr = head;
    Node *nextNode = NULL;
    Node *otherNode = NULL;

    while (curr) {
        nextNode = curr->next;
        otherNode = nextNode;
        curr->next = NULL;
        nextNode->next = curr;
        
    }
}

int main() {
    int arr[] = {2, 4, 6, 8};
    for (int i = 0; i<4; i++) {
        insertVal(arr[i]);
    }
    printLL();
}