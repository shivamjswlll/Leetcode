class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        if(days == 1) return r;
        int ans = 0;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            bool canLoad = true;
            int maxLoad = mid;
            int wt = 0;
            int cntdays = 1;

            for(int i = 0;i<n;i++){
                if(wt + weights[i] <= maxLoad){
                    wt += weights[i];
                }
                else{
                    cntdays++;
                    wt = weights[i];
                }
                if(cntdays > days){
                    canLoad = false;
                    break;
                }
            }
            if(canLoad){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};