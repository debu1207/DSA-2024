/*
Problem Statement:
 Given the head of a linked list, rotate the list to the right by k places.

Examples:

Example 1:
Input:
	head = [1,2,3,4,5] 
	k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.
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
    }
};

void insertNode(ListNode *head, int data) {
    ListNode *newnode = new ListNode(data);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    else {
        ListNode *curr = head;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = newnode;
    }
}

void printLL(ListNode *head) {
    ListNode * curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

/*
1. Calculate the length of linked list
2. connect the last node to the first node, converting it to the linked list
3. Iterate to cut the last node and start node of k%length of the list rotated list
*/

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    
    ListNode *temp = head;
    int length = 1;
    while (temp->next != NULL) {
        ++ length;
        temp = temp->next;
    }

    temp->next = head;
    k = k % length;
    int end = length - k;
    while(end--) temp=temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    ListNode *head = new ListNode(arr[0]);
    head->next = NULL;
    for (int i = 1; i<n; i++)
        insertNode(head, arr[i]);

    printLL(head);
    ListNode *rhead = rotateRight(head, 4);
    printLL(rhead);
}