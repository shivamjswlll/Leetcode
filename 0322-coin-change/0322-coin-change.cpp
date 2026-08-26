class Solution {
    int solve(int idx,int target,vector<int> &coins,vector<vector<int>> &dp){
        if(idx >= coins.size() || target < 0) return 1e5;

        if(dp[idx][target] != -1)  return dp[idx][target];
        if(target == 0){
            return 0;
        }

        int take = 1 + solve(idx,target-coins[idx],coins,dp);
        int notTake = solve(idx+1,target,coins,dp);

        return dp[idx][target] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(0,amount,coins,dp);

        return ans==1e5 ? -1:ans;
    }
};