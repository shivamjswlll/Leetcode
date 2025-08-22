class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        long long ans = 0;

        while(r < n){
            if(r== 0 || nums[r] != nums[r-1]){
                ans += r-l+1;
            }
            else{
                l = r;
                ans += 1;
            }
            r++;
        }
        return ans;
    }
};