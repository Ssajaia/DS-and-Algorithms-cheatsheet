#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

bool search(TreeNode* root, int val) {
    while (root) {
        if (val == root->val) return true;
        root = val < root->val ? root->left : root->right;
    }
    return false;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (val < root->val) root->left = deleteNode(root->left, val);
    else if (val > root->val) root->right = deleteNode(root->right, val);
    else {
        if (!root->left) { TreeNode* temp = root->right; delete root; return temp; }
        if (!root->right) { TreeNode* temp = root->left; delete root; return temp; }
        TreeNode* minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    }
    return root;
}

bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

int main() {
    TreeNode* root = nullptr;
    for (int v : {5, 3, 7, 1, 4, 6, 8}) root = insert(root, v);
    cout << search(root, 4) << "\n";
    root = deleteNode(root, 3);
    cout << search(root, 3) << "\n";
    cout << isValidBST(root) << "\n";
    return 0;
}