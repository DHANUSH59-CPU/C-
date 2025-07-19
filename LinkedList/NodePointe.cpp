#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next=b; // means (*a).next=b , here is a pointer storing node adress , here b is also a pointer
    b->next=c;
    c->next=d;

    Node* temp=a;
    while(temp!=NULL){
        cout<<temp->val<<" "; // go to the adress which is stored in temp and point to val of the adress
        temp=temp->next;
    }

    // now lets print b and c
    cout<<endl;
    cout<<a->next->val;
    cout<<endl;
    cout<<a->next->next->val;
}