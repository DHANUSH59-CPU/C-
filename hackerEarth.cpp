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
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node* rev(Node* head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    Node* curr = head;
    
    while(curr != NULL){
        if(curr->val % 2 == 0){
            Node* start = prev;
            Node* end = curr;
            while(end != NULL && end->val % 2 == 0){
                prev = end;
                end = end->next;
            }
            
            Node* a = start->next;
            Node* b = end;
            
            // Reverse the sublist from a to prev
            Node* p = NULL;
            Node* c = a;
            Node* n = a;
            while(c != b){
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            
            start->next = p;
            a->next = b;
            
            curr = b;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return dummy->next;
}

int main(){
    string s;
    cout << "Enter the elements of linked list : ";
    getline(cin, s);
    stringstream ss(s);
    int x;
    LinkedList ll;
    while(ss >> x){
        ll.insertAttail(x);
    }
    cout << "Original list: ";
    ll.display();
    ll.head = rev(ll.head);
    cout << "Modified list: ";
    ll.display();
    return 0;
}