#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};


TreeNode* construct(int arr[], int n) {
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;

    while (!q.empty() && i < n) {
        TreeNode* temp = q.front();
        q.pop();

        TreeNode* l = nullptr;
        TreeNode* r = nullptr;

        if (i < n && arr[i] != INT_MIN) l = new TreeNode(arr[i]);
        if (j < n && arr[j] != INT_MIN) r = new TreeNode(arr[j]);

        temp->left = l;
        temp->right = r;

        if (l != nullptr) q.push(l);
        if (r != nullptr) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}

int levels(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void nthlevel(TreeNode* root, int curr, int level) {
    if (root == NULL) return;

    if (curr == level) {
        cout << root->val << " ";
        return;
    }
    nthlevel(root->left, curr + 1, level);
    nthlevel(root->right, curr + 1, level);
}

void levelOrder(TreeNode* root) {
    int g = levels(root);
    for (int i = 1; i <= g; i++) {
        nthlevel(root, 1, i);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 25, 26, 29, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = construct(arr, n);
    levelOrder(root);
}
