class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int zero = 0;
        int chance = 1;
        while(r < n){
            if(nums[r] == 1){
                while(r < n && (nums[r] == 1 || chance)){
                    if(nums[r] == 0){
                        chance--;
                        zero = r;
                    }
                    r++;
                }
                    if(l != 0 && chance == 1){
                        ans = max(ans,r-l);
                    }
                    else{
                    ans = max(ans,r-l-1);
                    }
                if(r == n) break;
              r = zero;
            }
            else{
                r++;
                l = r;
                chance = 1;
            }
        }

        return ans;

    }
};