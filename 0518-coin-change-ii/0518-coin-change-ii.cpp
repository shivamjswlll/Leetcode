class Solution {
    int solve(int idx,int target,vector<int> &coins,vector<vector<int>> &dp){
        if(idx >= coins.size()){
            if(target == 0) return 1;
            return 0;
        }

        if(target < 0) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        int take = solve(idx,target-coins[idx],coins,dp);
        int notTake = solve(idx+1,target,coins,dp);

        return dp[idx][target] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};