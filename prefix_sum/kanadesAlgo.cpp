#include <iostream>
#include <vector>
#include <climits> // for INT_MIN

using namespace std;

void maxSubArrayWithIndices(vector<int>& nums, int& max_sum, int& start, int& end) {
    max_sum = INT_MIN;
    int current_sum = 0;
    start = 0;
    int temp_start = 0; // temporary start index
    
    for (int i = 0; i < nums.size(); i++) {
        current_sum += nums[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }
}

int main() {
    vector<int> nums = {4, 3, 1, 5, 6};
    int max_sum, start, end;
    
    maxSubArrayWithIndices(nums, max_sum, start, end);
    
    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Subarray from index " << start << " to " << end << ": [";
    
    // Print the subarray elements
    for (int i = start; i <= end; i++) {
        cout << nums[i];
        if (i != end) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}