// Remove Nth node from the end of linked list
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
    if (head = NULL) {
        cout << "[ ]" << endl;
        return;
    }
    ListNode * curr = head;
    while (curr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    ListNode *fastp = head;
    ListNode *slowp = head;

    for (int i = 0 ;i<n; i++)
        fastp=fastp->next;
    
    if (fastp== NULL)
        return head->next;
    
    while (fastp->next) {
        fastp = fastp->next;
        slowp = slowp->next; 
    }

    ListNode * delnode = slowp->next;
    slowp->next = slowp->next->next;
    delete delnode;
    return head;
}

int main() {
    int arr[] = {1};
    int n = sizeof(arr)/sizeof(int);
    ListNode *head = new ListNode(arr[0]);
    head->next = NULL;
    for (int i = 1; i<n; i++)
        insertNode(head, arr[i]);
    printLL(head);
    ListNode *newhead = removeNthFromEnd(head, 3);
    printLL(newhead);
}