class Solution {
    int solve(int idx,vector<int> &coins,int target,vector<vector<int>> &dp){
        if(idx>= coins.size()){
            if(target == 0) return 0;
            return 1e8;
        }
        if(target < 0) return 1e8;
        if(dp[idx][target] != -1) return dp[idx][target];
        int take = 1+solve(idx,coins,target-coins[idx],dp);
        int notTake = solve(idx+1,coins,target,dp);

        return dp[idx][target] = min(take ,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(0,coins,amount,dp);
        if(ans == 1e8) return -1;
        return ans;
    }
};