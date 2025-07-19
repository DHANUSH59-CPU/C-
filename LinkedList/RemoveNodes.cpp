#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAttail(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout <<temp->val <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node* remov(Node* head){
    stack<Node*> st;

    Node* temp = head->next;
    st.push(head);
    while(temp){
        while(st.size() > 0 && temp->val >= st.top()->val){
            st.pop();
        }
        st.push(temp);
        temp = temp->next;
    }

    // head = st.top();
    // Node* dummy = head;
    Node* newHead = NULL;
    st.pop();
    while(st.size() > 0){
        Node* dummy = st.top();
        dummy -> next = newHead;
        newHead = dummy;
        st.pop();
    }
    return newHead;
}

int main(){
    string s;
    cout<<"Enter the elements of string : ";
    getline(cin,s);
    stringstream ss(s);
    int x;
    LinkedList ll;
    while(ss >> x){
        ll.insertAttail(x);
    }
    ll.display();
    ll.head = remov(ll.head);
    ll.display();

}