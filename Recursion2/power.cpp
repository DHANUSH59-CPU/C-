#include<iostream>
using namespace std;

int pow(int a,int b){
    if(b==1) return a;
    int ans=pow(a,b/2);
    if(b%2==0) return ans*ans;
    if(b%2!=0) return ans*ans*a;
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