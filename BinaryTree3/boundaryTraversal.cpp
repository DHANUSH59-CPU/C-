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

TreeNode* construct(int arr[],int n){
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i < n){
        TreeNode* temp = q.front();
        q.pop();
        // cout<<temp->val<<" ";
        TreeNode* l;
        TreeNode* r;
        if(arr[i]!=INT_MIN) l=new TreeNode(arr[i]);
        else l=NULL;
        if(arr[j]!=INT_MIN) r=new TreeNode(arr[j]);
        else r=NULL;

        temp->left=l;
        temp->right=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}

int levels(TreeNode* root){
    if(root==NULL) return 0;

    return 1 + max(levels(root->left),levels(root->right));
}

void nthlevel(TreeNode* root,int curr,int level){
    if(root==NULL) return;

    if(curr==level){
        cout<<root->val<<" ";
        return;
    }
    nthlevel(root->left,curr+1,level);
    nthlevel(root->right,curr+1,level);
}

void levelOrder(TreeNode* root){
    int g = levels(root);
    for(int i=1;i<=g;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}

void leftboundary(TreeNode* root){
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    leftboundary(root->left);
    if(root->left==nullptr)  leftboundary(root->right);
}

void bottomnodes(TreeNode* root){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) cout<<root->val<<" ";
    bottomnodes(root->left);
    bottomnodes(root->right);
}

void rightboundary(TreeNode* root){
    if(root == nullptr) return;

    if(root->left==nullptr && root->right==nullptr) return;
    rightboundary(root->right);
    if(root->right == nullptr) rightboundary(root->left);
    cout<<root->val<<" ";
}

int main(){
    int arr[] = {
        1, 2, 3,
        4, 5, INT_MIN, 6,
        7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, 11,
        INT_MIN, 12, INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN,
        17,INT_MIN ,INT_MIN, 18, INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN,
        20, 21, 22, 23, INT_MIN, 24, 25, 26, 29, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN
    };
    
        int n=sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = construct(arr,n);
    // levelOrder(root);
    leftboundary(root);
    bottomnodes(root);
    rightboundary(root);
}