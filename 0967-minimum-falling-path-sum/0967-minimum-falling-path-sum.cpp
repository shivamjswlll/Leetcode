class Solution {
    int solve(int row,int col,vector<vector<int>> &matrix,vector<vector<int>> &dp){

        int n = matrix.size();

        if(row >= n || col >= n || row < 0 || col < 0) return 1e7;

        if(dp[row][col] != 1e9) return dp[row][col];

        if(row == n-1) return matrix[row][col];

        int left = matrix[row][col] + solve(row+1,col-1,matrix,dp);
        int down = matrix[row][col] + solve(row+1,col,matrix,dp);
        int right = matrix[row][col] + solve(row+1,col+1,matrix,dp);

        return dp[row][col] = min(left,min(down,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i = 0;i<n;i++){
            ans = min(ans,solve(0,i,matrix,dp));
        }

        return ans;
    }
};