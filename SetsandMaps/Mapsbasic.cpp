#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> m;
    // It is same as pair
    pair<string,int> p1;
    unordered_map<char,int> m1;
    p1.first = "Dhanush";
    p1.second = 1;
    pair<string,int> p2;
    p2.first = "Monu L";
    p2.second = 10;
    pair<string,int> p3;
    p3.first = "Tarun";
    p3.second = 9;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);

    for(auto ele : m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    m1['a'] = 1;
    // cout<<m1.first<<" "<<m1.second; (This is Wrong)
    for(auto ele : m1){
        cout<<ele.first<<" "<<ele.second;
    }
}