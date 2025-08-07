class Solution {
    int solve(int row,int col,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        int m = triangle.size();

        if(dp[row][col] != 1e9) return dp[row][col];

        if(row ==  m-1) return triangle[row][col];

        int downl = triangle[row][col] + solve(row+1,col,triangle,dp);
        int downr = triangle[row][col] + solve(row+1,col+1,triangle,dp);

        return dp[row][col] = min(downl,downr);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,1e9));
        return solve(0,0,triangle,dp);
    }
};