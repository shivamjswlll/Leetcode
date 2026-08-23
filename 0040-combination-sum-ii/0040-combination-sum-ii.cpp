class Solution {
    void solve(int idx,vector<int> &candidates,int target,vector<int> temp,vector<vector<int>> &ans){
        if(idx >= candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
                return;
        }

        if(target < 0 ) return;

        temp.push_back(candidates[idx]);
        solve(idx+1,candidates,target-candidates[idx],temp,ans);
        temp.pop_back();

        idx = idx + 1;
        while(idx < candidates.size() && idx > 0 &&  candidates[idx] == candidates[idx-1]){
            idx++;
        }
        solve(idx,candidates,target,temp,ans);

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());

        solve(0,candidates,target,temp,ans);

        return ans;
    }
};