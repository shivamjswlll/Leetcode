class Solution {
    int solve(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
        int n1 = word1.size();
        int n2 = word2.size();

        if(i >= n1 && j>= n2) return 0;
        if(i >= n1) return n2-j;
        if(j>= n2) return n1-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return solve(i+1,j+1,word1,word2,dp);
        }

        int insert =1+ solve(i,j+1,word1,word2,dp);
        int del =1+ solve(i+1,j,word1,word2,dp);
        int rep = 1 + solve(i+1,j+1,word1,word2,dp);

        return dp[i][j] = min(insert,min(del,rep));

    }
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};