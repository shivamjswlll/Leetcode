class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int l = 1;
        int r = x;

        while(l <= r){
            int mid = l + (r-l)/2;
            long long sq = (long long)mid*mid;

            if(sq == x) return mid;

            if(sq < x){
                l = mid+1;
                ans = mid;
            }
            else{
                r = mid-1;
            }
            

        }
        return ans;
    }
};