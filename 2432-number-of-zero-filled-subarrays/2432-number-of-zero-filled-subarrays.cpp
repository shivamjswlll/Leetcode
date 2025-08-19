class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        long long ans = 0;
        while(i < n){
            if(nums[i] == 0){
                int start = i;
                while(i< n && nums[i] == 0) i++;
                long long temp = ((long long)(i-start)*(i-start+1))/2;
                ans += temp;
            }
            
            i++;
        }
        return ans;
    }
};