#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val){
        this->val=val;
        this->next=nullptr;
        this->prev=nullptr;
    }  
};

class DLL{
public:
    ListNode* head;
    ListNode* tail;
    int size=0;
    DLL(){
        head=tail=nullptr;
        size=0;
    }
    void insertAttail(int val){
        ListNode* temp=new ListNode(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }

    void insertAthead(int val){
        ListNode* temp=new ListNode(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }

    void insertAtIdx(int idx,int val){
        ListNode* t=new ListNode(val);
        if(idx==0) insertAthead(val);  
        else if(idx==size) insertAttail(val);
        else if(idx<0 || idx>size) cout<<"Invalid Index!";
        else{
            if(idx<=size/2){
                ListNode* temp=head;
                for(int i=1;i<=idx-1;i++){
                    temp=temp->next;
                }
                t->next=temp->next;
                temp->next->prev=t;
                t->prev=temp;
                temp->next=t;
                size++;
            }
            else{
                ListNode* temp=tail;
                for(int i=1;i<=(size-idx);i++){
                    temp=temp->prev;
                }
                t->next=temp->next;
                temp->next->prev=t;
                t->prev=temp;
                temp->next=t;
                size++;
            }
          
        }
    }

    void display(){
        ListNode* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
    DLL ll;
    ll.insertAthead(10);
    ll.insertAttail(20);
    ll.insertAttail(30);
    ll.insertAttail(40);
    ll.insertAthead(100);
    ll.insertAtIdx(3,60);
    ll.display();
    return 0;
}