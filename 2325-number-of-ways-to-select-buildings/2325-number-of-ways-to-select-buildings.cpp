class Solution {
public:
    long long numberOfWays(string s) {
        long long zero = 0;
        long long one = 0;
        long long zeroOne = 0;
        long long onezero = 0;
        long long ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '0'){
                ans += zeroOne;
                onezero += one;
                zero += 1;
            }
            else{
                ans += onezero;
                zeroOne += zero;
                one += 1;
            }
        }
        return ans;
    }
};