#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this -> val = val;
        this -> right = NULL;
        this -> left = NULL;
    }
};

TreeNode* construct(int arr[], int n){
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()>0 && i < n){
        TreeNode* temp = q.front();
        q.pop();
        TreeNode* l;
        TreeNode* r;

        if(arr[i] != INT_MIN) l = new TreeNode(arr[i]);
        else l = NULL;
        if(arr[j] != INT_MIN) r = new TreeNode(arr[j]);
        else r = NULL;

        temp -> left = l;
        temp -> right = r;

        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}

void display(TreeNode* root){
    if(root == nullptr) return;

    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

void topview(TreeNode* root){
    unordered_map<int,int> m; // Where it stores level and Node->val
    queue < pair<TreeNode*, int> > q;  // Here queue stores the Node and level
    pair<TreeNode*, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size() > 0){
        TreeNode* temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level) == m.end()){ // if it is not there
            m[level] = temp -> val;
        }

        if(temp->left != NULL){
            pair<TreeNode*, int> p;
            p.first = temp -> left;
            p.second = level - 1;
            q.push(p);
        }

        if(temp -> right != NULL){
            pair<TreeNode*, int> p;
            p.first = temp -> right;
            p.second = level + 1;
            q.push(p);
        }
    }
    // Now lets find the minLevel and maxLevel
    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;

    for(auto ele : m){
        int level = ele.first;
        minLevel = min(minLevel,level);
        maxLevel = max(maxLevel,level);
    }

    for(int i = minLevel; i <= maxLevel; i++){
        cout << m[i] << " ";
    }
}


int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = construct(arr,n);

    // display(root);
    topview(root);

}