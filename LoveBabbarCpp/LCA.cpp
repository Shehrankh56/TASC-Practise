#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to build tree level-wise
Node* buildTreeLevelOrder() {
    cout << "Enter root node value (-1 for NULL): ";
    int val;
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Optional: Level Order Traversal
void LevelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
}

// LCA Solution
class Solution {
public:
    Node* lca(Node* root, int n1, int n2) {
        if (root == NULL) return NULL;

        if (root->data == n1) return root;
        if (root->data == n2) return root;

        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        if (leftAns == NULL && rightAns == NULL) {
            return NULL;
        } else if (leftAns == NULL && rightAns != NULL) {
            return rightAns;
        } else if (leftAns != NULL && rightAns == NULL) {
            return leftAns;
        } else {
            return root;
        }
    }
};

int main() {
    Node* root = buildTreeLevelOrder();

    cout << "\nLevel Order Traversal of Tree:\n";
    LevelOrderTraversal(root);

    int n1, n2;
    cout << "\nEnter two node values to find their LCA: ";
    cin >> n1 >> n2;

    Solution sol;
    Node* ans = sol.lca(root, n1, n2);

    if (ans != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    else
        cout << "One or both nodes not found in tree." << endl;

    return 0;
}
