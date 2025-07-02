#include <iostream>
#include <queue>
using namespace std;

// Definition of binary tree node
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

// Function to build binary tree level-wise
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

// Recursive function to check if a path with target sum exists
bool solve(Node* root, int target, int sum) {
    if (root == NULL) return false;

    sum += root->data;

    // Leaf node condition
    if (root->left == NULL && root->right == NULL) {
        if (sum == target) {
            return true;
        } else {
            return false;
        }
    }

    bool leftAns = solve(root->left, target, sum);
    bool rightAns = solve(root->right, target, sum);

    return leftAns || rightAns;
}

// Wrapper function
bool hasPathSum(Node* root, int target) {
    int sum = 0;
    return solve(root, target, sum);
}

int main() {
    Node* root = buildTreeLevelOrder();

    int target;
    cout << "\nEnter target sum: ";
    cin >> target;

    if (hasPathSum(root, target)) {
        cout << " A root-to-leaf path with sum " << target << " exists!" << endl;
    } else {
        cout << " No such path exists in the tree." << endl;
    }

    return 0;
}
