class Solution {
    int solve(int i,int j ,string &s,vector<vector<int>> &dp){
        if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }
        int addFront = 1 + solve(i,j-1,s,dp);
        int addLast = 1 + solve(i+1,j,s,dp);

        return dp[i][j] =  min(addFront,addLast);
    }
public:
    int minInsertions(string s) {
        int i = 0;
        int j = s.size()-1;
        vector<vector<int>> dp(j+1,vector<int>(j+1,-1));
        return solve(i,j,s,dp);
    }
};