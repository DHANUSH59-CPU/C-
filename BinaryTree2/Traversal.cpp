#include<bits/stdc++.h>
using namespace std;


class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=nullptr;
    }
};
                     // DFS
void preorder(TreeNode* root){
    if(root==nullptr) return;

    cout<<root->val<<" "; // work
    preorder(root->left); // call
    preorder(root->right); // call
}

void inorder(TreeNode* root){
    if(root==nullptr) return;

    inorder(root->left); // call
    cout<<root->val<<" "; // work
    inorder(root->right); // call
}

void postorder(TreeNode* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a -> left = b;
    a -> right = c;
    b -> left = d;
    b -> right = e;
    c -> left = f;
    c -> right = g;

    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
}