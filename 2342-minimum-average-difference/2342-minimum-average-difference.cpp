class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for(auto it:nums){
            total += it;
        }
        long long  leftSum = 0;
        long long rightSum = total;
        int mn = INT_MAX;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            rightSum -= nums[i];
            leftSum = total - rightSum;
            long long leftnum = i+1;
            long long rightnum = n-(i+1);
            long long avgleft = leftSum/leftnum;
            long long avgright = 0;
            if(rightnum != 0)
            avgright = rightSum/rightnum;
            else{
                avgright = 0;
            }
          

            int minAvg = abs(avgleft-avgright);
            // cout<<minAvg<<" "<<i<<endl;
            if(minAvg < mn){
                ans = i;
                mn = minAvg;
            }
        }
        return ans;
    }
};