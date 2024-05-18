/*
Write a function to delete a node in a singly-linked list. 
You will not be given access to the head of the list instead, 
you will be given access to the node to be deleted directly. 
It is guaranteed that the node to be deleted is not a tail node in the list.

Examples:
Example 1:
Input:
 Linked list: [1,4,2,3]
       Node = 2
Output:
Linked list: [1,4,3]
Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].
*/
#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode * next;
    
    ListNode() {
        next = NULL;
    }
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

ListNode* insertNode(ListNode *head, int data) {
    ListNode *newnode = new ListNode(data);

    if (head == NULL) {
        head = newnode;
        return head;
    }
    else {
        ListNode *curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = newnode;
    }
    return newnode;
}

void printLL(ListNode *head) {
    ListNode * curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
    return;
}

int main() {
    ListNode *head = new ListNode(1);

    ListNode *node1 = insertNode(head, 2);
    ListNode *node2 = insertNode(head, 3);
    ListNode *node3 = insertNode(head, 4);

    printLL(head);

    deleteNode(node1);

    printLL(head);
    
}