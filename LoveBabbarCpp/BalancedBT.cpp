#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Function to build tree level-wise
TreeNode* buildTreeLevelOrder() {
    cout << "Enter root node value (-1 for NULL): ";
    int val;
    cin >> val;

    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->val << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Function for level-order traversal
void LevelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << front->val << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
}

// Solution class
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool currNode = (diff <= 1);
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        return currNode && leftAns && rightAns;
    }
};

int main() {
    TreeNode* root = buildTreeLevelOrder();

    cout << "\nLevel Order Traversal:\n";
    LevelOrderTraversal(root);

    Solution sol;
    if (sol.isBalanced(root))
        cout << "\n\nThe tree is balanced " << endl;
    else
        cout << "\n\nThe tree is NOT balanced" << endl;

    return 0;
}
