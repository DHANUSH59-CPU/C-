#include<bits/stdc++.h>
using namespace std;

class Node{  // User Defined data-type
public:
        int val;
        Node* next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};

class LinkedList{ // User Defined data structure
public:
        Node* head;
        Node* tail;
        int size=0;

        void insertAtTail(int val){
            Node* temp = new Node(val);
            if(size==0) head = tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        Node* retu(int idx){
            return head;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

Node* reverselist(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* Next=head;
    while(curr){
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    return prev;
}

void display2(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}



int main(){
    int n;
    cout<<"Entered the number :";
    cin>>n;
    cin.ignore();
    LinkedList ll;
    string s;
    getline(cin,s);
    int x;
    stringstream ss(s);
    while( ss >> x){
        ll.insertAtTail(x);
    }

    Node* head=ll.retu(0);
    ll.display();
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Node* temp=head;
    Node* b = reverselist(head);
    // ll.display();
    display2(b);
}