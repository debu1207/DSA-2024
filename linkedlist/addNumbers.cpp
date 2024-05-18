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

// Brute force
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ptr1 = l1;
    ListNode *ptr2 = l2;

    int num1 = 0, w1 = 1;
    int num2 = 0, w2 = 1;
    while (ptr1) {
        num1 += ptr1->val  * w1;
        w1 *= 10;
        ptr1 = ptr1->next; 
    }
    while (ptr2) {
        num2 += ptr2->val  * w2;
        w2 *= 10;
        ptr2 = ptr2->next;
    }
    int sum = num1 + num2;
    int temp = sum % 10;
    sum /=10;
    ListNode *ans = new ListNode(temp);
    ListNode *curr = ans;
    while (sum) {
        temp = sum % 10;
        ListNode *newnode = new ListNode(temp);
        curr->next = newnode;
        curr = newnode;
        sum /= 10;
    }
    curr->next = NULL;
    return ans;
}

ListNode * Optimal_addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    int carry = 0;

    while ((l1 || l2) || carry) {
        int sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        ListNode *newnode = new ListNode(sum %10);
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = NULL;
    return dummy->next;
}

int main() {
    int arr1[] = {9,9,9,9,9,9,9};
    int arr2[] = {9,9,9,9};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    ListNode *head1 = new ListNode(arr1[0]);
    ListNode* head2 = new ListNode(arr2[0]);
    head1->next = NULL;
    head2->next = NULL;
    for (int i = 1; i<n1; i++)
        insertNode(head1, arr1[i]);
    for (int i = 1; i<n2; i++)
        insertNode(head2, arr2[i]);
    
    printLL(head1);
    printLL(head2);

    ListNode *ans = Optimal_addTwoNumbers(head1, head2);
    printLL(ans);
}