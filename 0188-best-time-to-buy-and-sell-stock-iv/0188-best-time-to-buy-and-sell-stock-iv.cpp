class Solution {
    int solve(int idx,int t,vector<int> &prices,vector<vector<int>> &dp){
        if(t < 0) return 0;
        if(idx >= prices.size()) return 0;

        if(dp[idx][t] != -1) return dp[idx][t];

        int profit = 0;
        if(t & 1){
            profit = max( (solve(idx+1,t-1,prices,dp) - prices[idx]), solve(idx+1,t,prices,dp));
        }
        else{
            profit = max( (prices[idx] + solve(idx+1,t-1,prices,dp)) , solve(idx+1,t,prices,dp));
        }
        return dp[idx][t] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return solve(0,2*k-1,prices,dp);
    }
};