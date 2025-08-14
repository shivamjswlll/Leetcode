class Solution {
    int solve(int i , int j , string &s1,string &s2,vector<vector<int>> &dp){
        int n1 = s1.size();
        int n2 = s2.size();

        if(i >= n1 || j >= n2) return 0;

        if(dp[i][j] != -1 ) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,s1,s2,dp);
        }
        int skip1 = solve(i+1,j,s1,s2,dp);
        int skip2 = solve(i,j+1,s1,s2,dp);


        return dp[i][j] = max(skip1,skip2);
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,s,s1,dp);
    }
};