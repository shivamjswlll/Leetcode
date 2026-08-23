class Solution {
    void solve(int idx,vector<int> &nums,vector<int> temp,vector<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(idx+1,nums,temp,ans);
        temp.pop_back();

        idx = idx+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        solve(idx,nums,temp,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());

        solve(0,nums,temp,ans);

        return ans;
    }
};