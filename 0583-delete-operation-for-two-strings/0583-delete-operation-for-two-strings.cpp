class Solution {
    int solve(int i, int j,string &s1,string &s2,vector<vector<int>> &dp){
        int n1 = s1.size();
        int n2 = s2.size();

        if(i >= n1) return n2-j;
        if(j >= n2) return n1-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        }

        int del = 1 + solve(i+1,j,s1,s2,dp);
        int insert = 1 + solve(i,j+1,s1,s2,dp);

        return dp[i][j] = min(del,insert);
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(0,0,word1,word2,dp);
    }
};