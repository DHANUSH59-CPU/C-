#include<iostream>
#include<bits/stdc++.h>
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
            tail -> next = temp;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp -> val << " ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};

Node* reverse(Node* head){
    Node* prev = NULL, *curr = head, *Next = head;
    while(curr){
        Next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

Node* add(Node* head){
    head = reverse(head);
    Node* temp = head;
    int carry = 0;
    int extra = 1;
    while(temp){
        if(extra > 0){
            if(temp->val + extra >= 10){
                temp->val = 0;
                carry++;
                temp = temp->next;
                extra--;
            }
            else{
                temp->val = temp->val + extra;
                temp = temp -> next;
                extra--;
                break;
        }
        } 
        if(carry > 0){
            if(temp->val + carry >= 10){
                temp->val = 0;
                carry++;
                temp = temp->next;
            }
            // carry--;
            else{
                temp->val = temp->val + carry;
            }
            carry--;
        }
    }
    if(carry > 0){
        Node* n = new Node(1);
        temp = head;
        while(temp -> next){
            temp = temp->next;
        }
        temp->next = n;
    }
    head = reverse(head);
    return head;
    
}
int main(){
    string s;
    cout<<"Enter the linked List : ";
    getline(cin,s);
    stringstream ss(s);
    int x;
    LinkedList ll;
    while(ss >> x){
        ll.insertAttail(x);
    }

    ll.display();

    ll.head = add(ll.head);
    ll.display();

}