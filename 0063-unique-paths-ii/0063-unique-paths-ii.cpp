class Solution {
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        if(row >= m || col >= n||grid[row][col] == 1) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        if(row == m-1 && col == n-1) return 1;

        int down = solve(row+1,col,grid,dp);
        int right = solve(row,col+1,grid,dp);

        return dp[row][col] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,dp);
    }
};