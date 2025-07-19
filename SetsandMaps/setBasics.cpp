#include<bits/stdc++.h>
// #include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    // Size
    cout << s.size() << endl;
    // lets pint them
    for(auto ele : s){
        cout<<ele<<" ";
    }
    cout << endl;
    // Lets find the target
    cout << "Enter the target : ";
    int target;
    cin >> target;
    if(s.find(target) != s.end()){
        cout<<"The target is Present"<<endl;
    }
    else{
        cout<<"The target is not Present"<<endl;
    }

    s.erase(3);
    for(auto ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
}