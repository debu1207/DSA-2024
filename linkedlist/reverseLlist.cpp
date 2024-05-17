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

ListNode * reverseLL(ListNode *head) { // Time: O(N) and Space: O(1)
    if (head->next) {
        ListNode *prev = NULL;
        ListNode *nextNode = NULL;
        ListNode *curr = head;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    return head;
}

ListNode *recursive(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else {
        ListNode *rev = recursive(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next= NULL;
        return rev;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    ListNode *head = new ListNode(arr[0]);
    head->next = NULL;
    for (int i = 1; i<n; i++)
        insertNode(head, arr[i]);

    printLL(head);
    ListNode *newhead = recursive(head);
    printLL(newhead);

}