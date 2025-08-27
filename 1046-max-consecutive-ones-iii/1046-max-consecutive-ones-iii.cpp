class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();

        while(r < n){
            while((r<n) && ( nums[r] == 1 || k > 0)){
                if(nums[r] == 0) k--;
                r++;
            }
            ans = max(ans,r-l);
            if( l < n &&nums[l] == 0){
                k++;
                l++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};