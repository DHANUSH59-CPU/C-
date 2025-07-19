#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
public:
    ListNode* head;
    ListNode* tail;
    int size;

    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAttail(int val){
        ListNode* temp = new ListNode(val);
        if(size == 0) head = tail =temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void display(){
        ListNode* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

ListNode* reverseGroup(ListNode* head,int k,int size){ // 1 2 3 4 5 6
    if(k<1 || k > size ) return head;

    ListNode* prev = NULL, *curr = head, *Next = head;
    int count = 0;
    while(count < k){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        count++;
    }
    size -= k;
    if(curr != NULL)  head->next = reverseGroup(curr,k,size);
    return prev;
   
}

int main(){
    LinkedList ll;
    string s;
    cout<<"Enter the space-saparated string : ";
    getline(cin,s);
    stringstream ss(s);
    int x;
    while(ss >> x){
        ll.insertAttail(x);
    }

    ll.display();
    int k;
    cout<<"Enter the val of k : ";
    cin>>k;
    cin.ignore();
    int size = ll.size;
    // cout<<size;
    ll.head = reverseGroup(ll.head,k,size);
    ll.display();
}