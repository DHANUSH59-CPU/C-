#include<iostream>
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
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    void insertAtIdx(int idx,int val){
        Node* t=new Node(val);
        Node* temp=head;
        if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
        else if(idx<0 || idx>size) cout<<"Invalid Index";
        else{
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }

    int getelementbyIdx(int idx){
        if(idx==0) return head->val;
        else if(idx==size-1) tail->val;
        else if(idx<0 || idx>size){
            cout<<"Invalid index ";
            return -1;
        }
        else{
            Node* temp=head;
            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }

    void deletehead(){
        head=head->next;
        return;
    }
    
    void deletetail(){
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }

    void deletebyIdx(int idx){
        if(idx==0){
            deletehead();
            return;
        } 
        else if(idx==size){
            deletetail();
        }
        else if(idx<0 || idx>size) cout<<"Inavalid Index ";
        else{
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
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

int main(){
    LinkedList ll;
    ll.insertAtTail(10); // {10->NULL}
    ll.display();
    ll.insertAtTail(20); //{10->20->NULL}
    ll.display();
    ll.insertAtTail(30); //{10->20->30->NULL}
    ll.insertAtTail(40); //{10->20->30->40->NULL}
    ll.insertAtTail(50); //{10->20->30->40->50->NULL}
    ll.display();
    ll.insertAtHead(80); // {80->10->20->30->40->50->NULL}
    ll.display();
    // cout<<ll.size;
    ll.insertAtIdx(5,90);
    ll.display();
    cout<<ll.getelementbyIdx(4)<<endl;
    ll.deletehead();
    ll.display();
    ll.deletetail();
    ll.display();
    ll.deletebyIdx(2);
    ll.display();

}