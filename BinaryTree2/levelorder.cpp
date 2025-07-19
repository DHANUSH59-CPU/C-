#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int levels(TreeNode* root){
    if(root==nullptr) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

void nthlevel(TreeNode* root,int curr,int level){
    if(root == nullptr) return;
    if(curr == level){
        cout<<root->val<<" ";
        // IF I PUT return here the code will be more optimised
        return;

        // there is another magic (if i put this if statement in middle of calls or at the end of calls the printing order would remain same)
    }
    nthlevel(root -> left,curr + 1,level);
    nthlevel(root -> right,curr + 1,level);
}

void nthlevelreverse(TreeNode* root,int curr,int level){
    if(root==nullptr) return;

    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    nthlevelreverse(root->right,curr+1,level);
    nthlevelreverse(root->left,curr+1,level);
}

void levelorder(TreeNode* root){
    int n = levels(root);
    for(int i = 1; i <= n; i++){
        nthlevelreverse(root, 1 , i);
        cout<<endl;
    }
}

void levelOrderQueue(TreeNode* root){ // BFS
    queue<TreeNode*> qt;
    qt.push(root);
    while(qt.size() > 0){
        TreeNode* temp = qt.front();
        qt.pop();
        cout << temp -> val << " ";
        if(temp -> left != NULL) qt.push(temp -> left);
        if(temp -> right != NULL) qt.push(temp -> right);
    }
    cout << endl;
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    // nthlevel(a,1,3);
    // levelorder(a);
    levelOrderQueue(a);

}