class Solution {
public:
    bool solve(int n,unordered_map<int,int> &mp){
        if(n == 1) return true;
        if(mp.find(n) != mp.end()) return false;

        int newN = 0;
        mp[n]++;
        while(n){
            int a = n % 10;
            n = n/10;
            newN += (a*a);
        }

        return solve(newN,mp);
    }
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        return solve(n,mp);
    }
};