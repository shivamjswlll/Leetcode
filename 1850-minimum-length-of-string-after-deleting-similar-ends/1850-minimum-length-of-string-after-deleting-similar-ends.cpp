class Solution {
    int solve(string &s){
        int l = 0;
        int r = s.size()-1;

        while(s[l] == s[r]){
            if(l==r) return 1;
            char temp = s[l];
            while(l<=r && s[l] == temp){
                l++;
            }
            while(r > l && s[r] == temp){
                r--;
            }
            
        }
        return r-l+1;
    }
public:
    int minimumLength(string s) {
        int len = solve(s);
        return len;
    }
};