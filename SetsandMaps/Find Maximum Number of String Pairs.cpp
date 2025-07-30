class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        unordered_map<string, vector<string>> m;

        for(auto ele : words){
            string key = ele;
            sort(key.begin(), key.end());
            m[key].push_back(ele);
        }

        int count  = 0;

        for(auto ele : m){
            if(ele.second.size() == 2){
                count++;
            }
        }

        return count;
    }
};

// 2744