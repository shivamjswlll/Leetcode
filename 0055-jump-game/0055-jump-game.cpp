class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int jump = nums[0];
        for(int i = 0;i<nums.size();i++){
            jump = max(nums[i],jump-1);
            if(jump == 0 && i != nums.size()-1) return false;
            if(i+jump >= nums.size()-1) return true;
        }
        return false;
    }
};