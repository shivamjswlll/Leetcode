class Solution {
public:
    int beautySum(string s) {
        map<char,int> mp;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            for(int j = i;j<s.size();j++){
                mp[s[j]]++;
                int mx = 0;
                int mn = INT_MAX;
                for(auto it:mp){
                    if(it.second > mx) mx = it.second;
                    if(it.second < mn) mn = it.second;
                }
                if(mn != INT_MAX &&  mx != 0) ans += (mx-mn);
            }
            mp.clear();
        }
        return ans;
    }
};