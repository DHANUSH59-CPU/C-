#include<iostream>
using namespace std;

int stair(int noOfStairs){
    if(noOfStairs==2) return 2;
    if(noOfStairs==1) return 1;
    return stair(noOfStairs-1) + stair(noOfStairs-2);
}

int main(){
    int n;
    cout<<"Enter the number of Stairs :";
    cin>>n;
    int x=stair(n);  // this is same as fibo
    cout<<x;
}