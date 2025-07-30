class Solution {
public:
    int reverse(int n){

        int ans = 0;
        while(n > 0){
            ans = ans * 10 +  (n % 10);
            n /= 10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int x = reverse(nums[i]);
            nums.push_back(x);
        }

        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }

        return s.size();
    }
};

// 2442