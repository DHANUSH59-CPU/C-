class Solution {
    public:
    vector<vector<int>> grid;
        int f(int r, int c){
            if(r == grid.size() - 1) return grid[r][c];
            int result = INT_MAX;
            result += grid[r][c] + min(f(r + 1, c) , f(r + 1, c + 1));
            return result;
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            grid = triangle;
            return f(0,0);
    
        }
    };

    // This is a mistake dont do it
     // if your using result = INT_MAX then you should use it inside min function also