class Solution {
    bool solve(int idx,int target,vector<int> &nums,vector<vector<int>> &dp){

        if(idx >= nums.size() || target < 0) return false;
        if(dp[idx][target] != -1) return dp[idx][target];
        if(target == 0) return true;

        bool take = solve(idx+1,target-nums[idx],nums,dp);
        bool notTake = solve(idx+1,target,nums,dp);

        return dp[idx][target] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0,[](int x,int y){
            return x+y;});
        if(sum & 1 != 0) return false;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>((sum/2) + 1, -1));
        return solve(0,sum/2,nums,dp);
    }
};