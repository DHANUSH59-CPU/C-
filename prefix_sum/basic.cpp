#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    // int n;
    string s;
    cout<<"Enter the string :";
    getline(cin,s);
    cout<<s<<endl;
    int n=s.length();
    stringstream ss(s);
    int temp;
    vector<int> arr;
    while(ss>>temp){
        arr.push_back(temp);
    }

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    // prefix sum
    for(int i=1;i<arr.size();i++){
        arr[i]=arr[i]+arr[i-1];
    }

    cout<<"Prefix sum :"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}