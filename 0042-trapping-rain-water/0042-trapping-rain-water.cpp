class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        int lmax = height[0];
        int rmax = height[height.size()-1];
        int ans = 0;

        while(l <= r){
            if(rmax >= lmax){
                if(height[l] > lmax){
                    lmax = height[l];
                }else{
                    ans +=(lmax-height[l]);
                }
                    l++;
            }else{
                if(height[r] > rmax){
                    rmax = height[r];
                }else{
                    ans += (rmax-height[r]);
                }
                    r--;
            }
        }

        return ans;
    }
};