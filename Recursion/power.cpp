#include<iostream>
using namespace std;

int pow(int a,int b){
    if(b==1) return a;
    return a*pow(a,b-1);
}

int main(){
    int a;
     cout<<"Enter the base number: ";
     cin>>a;
     int b;
     cout<<"Enter the power :";
     cin>>b;
     int x=pow(a,b);// a to the power b
     cout<<x;
}