class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> freq(n,1);
        int mx = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev < i;prev++){
                if(nums[i] > nums[prev]){
                    if(1 + dp[prev] > dp[i]){
                        dp[i] = 1 + dp[prev];
                        freq[i] = freq[prev];
                    }
                    else if(dp[i] == 1+dp[prev]){
                        freq[i] += freq[prev];
                    }
                }
            }
            mx = max(mx,dp[i]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(dp[i] == mx){
                ans += freq[i];
            }
        }
        return ans;
    }
};