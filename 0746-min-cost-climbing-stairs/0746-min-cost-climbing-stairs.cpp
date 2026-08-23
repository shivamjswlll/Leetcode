class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0) return 0;
        if(cost.size() == 1) return cost[0];
        if(cost.size() == 2) return min(cost[0],cost[1]);

        vector<int> dp1(cost.size());
        vector<int> dp2(cost.size());

        dp1[0] = cost[0];
        dp1[1] = cost[0] + cost[1];
        dp2[0] = INT_MAX;
        dp2[1] = cost[1];
        for(int i = 2;i<cost.size();i++){
          dp1[i] = cost[i] + min(dp1[i-1],dp1[i-2]);
          dp2[i] = cost[i] + min(dp2[i-1],dp2[i-2]);
        }
        int n = cost.size()-1;
        
        int mn = min(dp1[n-1],dp1[n]);
        int mnn = min(dp2[n-1],dp2[n]);
        return min(mn,mnn);
    }
};