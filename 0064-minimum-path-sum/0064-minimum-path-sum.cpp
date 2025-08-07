class Solution {
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m || col >= n) return 1e8;

        if(dp[row][col] != -1) return dp[row][col];

        if(row == m-1 && col == n-1) return grid[row][col];

        int right = grid[row][col] + solve(row,col+1,grid,dp);
        int down = grid[row][col] + solve(row+1,col,grid,dp);

        return dp[row][col] = min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};