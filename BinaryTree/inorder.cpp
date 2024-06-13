#include <iostream>
#include <vector>
using namespace std;

// Inorder traversal of binary tree

struct node {
    int data;
    node* left;
    node* right;

    node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node * root, vector<int> & ans) { // Time: O(N)
    if (root == NULL)
        return;
    
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(node * root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main() {
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right= new node(5);
    root->right->left = new node(6);
    vector<int> ans = inorderTraversal(root);
    for (int n : ans)
        cout << n << " ";
}