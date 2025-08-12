class Solution {
public:
    const int MOD = 1e9 + 7;
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        int cnt = 0;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum = (sum + nums[i]);
            prefixSum[i] = sum;
        }

        for(int i = 0;i<n-1;i++){
            long long leftsum = prefixSum[i];
            long long rightsum = prefixSum[n-1] - prefixSum[i];
            if(leftsum >= rightsum) cnt++;
        }

        return cnt;

    }
};