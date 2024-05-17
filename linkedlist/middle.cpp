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

ListNode * middle(ListNode *head) {
    int l = 0;
    ListNode *curr = head;
    while (curr) {
        l++;
        curr = curr->next;
    }
    if (l == 1) {
        return head;
    }
    if (l % 2 == 0){
        l /= 2;
    } else {
        l /=2;
    }
    curr = head;
    while (l--) {
        curr = curr->next;
    }
    return curr; 
}

ListNode * Optimal_middle(ListNode * head) {
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    while (ptr2 && ptr2->next) {
        ptr1 = ptr1->next;
        if (ptr2->next && ptr2->next->next)
            ptr2 = ptr2->next->next;
        else break;
    }
    return ptr1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);
    ListNode *head = new ListNode(arr[0]);
    head->next = NULL;
    for (int i = 1; i<n; i++)
        insertNode(head, arr[i]);
    
    printLL(head);
    ListNode *mid = Optimal_middle(head);
    cout << "Middle: " << mid->val << endl;
}