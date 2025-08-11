
class Solution {
    int solve(int idx,int sum,int target,vector<int> &nums){
        if(idx >= nums.size()){
            if(sum == target) return 1;
            return 0;
        }

        int add = solve(idx+1,sum+nums[idx],target,nums);
        int sub = solve(idx+1,sum-nums[idx],target,nums);

        return  add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(0,0,target,nums);
    }
};