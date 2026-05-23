#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* lcaBinaryTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lcaBinaryTree(root->left, p, q);
    TreeNode* right = lcaBinaryTree(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}

const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;

void dfs(const vector<vector<int>>& adj, int u, int parent, int d) {
    up[u][0] = parent;
    depth[u] = d;
    for (int i = 1; i < LOG; i++)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v : adj[u])
        if (v != parent) dfs(adj, v, u, d + 1);
}

int lcaBinaryLifting(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
        if ((diff >> i) & 1) u = up[u][i];
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
    return up[u][0];
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    TreeNode* lca = lcaBinaryTree(root, root->left, root->right);
    cout << lca->val << "\n";
    return 0;
}