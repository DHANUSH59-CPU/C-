class Solution {
public:
    // vector<string> arr;
    vector<string> ans;
    unordered_map<char, string> phoneMap;

    void f(string digits, int i, int t, string s){
        if(t == digits.size()){
            ans.push_back(s);
            return;
        }

        string x = phoneMap[digits[t]];
        for(int j = 0; j < x.size(); j++){
            f(digits, j, t + 1, s + x[j]);
        }
    }
    vector<string> letterCombinations(string digits) { 
        phoneMap['2'] = "abc";
        phoneMap['3'] = "def";
        phoneMap['4'] = "ghi";
        phoneMap['5'] = "jkl";
        phoneMap['6'] = "mno";
        phoneMap['7'] = "pqrs";
        phoneMap['8'] = "tuv";
        phoneMap['9'] = "wxyz";
        if(digits == ""){
            return {};
        }
        f(digits, 0, 0, "");
        return ans;
    }
};

// 17