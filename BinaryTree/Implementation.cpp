#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void display(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

// Lets Find Sum

int sum(TreeNode* root){
    if(root==NULL) return 0;
    return root -> val + sum(root->left) + sum(root->right);
}

// Lets Find Maximum in Tree
// Hint is to divide tree in 3 parts.

int max(TreeNode* root){
    if(root==NULL) return INT_MIN;
    int leftmax=max(root->left);
    int rightmax=max(root->right);
    return max(root->val,max(leftmax,rightmax));
}

// Lets Find the Min value 
int minimum(TreeNode* root){
    if(root==NULL) return INT_MAX;
    int leftmin=minimum(root->left);
    int rightmin=minimum(root->right);
    return min(root->val,min(leftmin,rightmin));
}

// Count the number of nodes
int count(TreeNode* root){
    if(root==nullptr) return 0;
    return 1 + count(root->left) + count(root->right);
}

int levels(TreeNode* root){
    if(root==nullptr) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

// Lets find the product;

int product(TreeNode* root){
    if(root==NULL) return 1;
    return root -> val * product(root->left) * product(root->right);
}

int main(){
    TreeNode* a = new TreeNode(90);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(6);
    TreeNode* e = new TreeNode(2);
    TreeNode* f = new TreeNode(8);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->right=f;
    display(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<max(a);
    cout<<endl;
    cout<<count(a);
    cout<<endl;
    cout<<levels(a);
    cout<<endl;
    cout<<product(a);
    cout<<endl;
    cout<<minimum(a);
}