class Solution {
    bool match(string &s1,string &s2){
        if(s1.size() == s2.size()) return false;
        int j = 0;
        int chance = 1;
        for(int i = 0;i<s1.size();i++){
           if(s1[i] == s2[j]){
                j++;
           }
           else if(chance){
            chance--;
            continue;
           }
           else return false;
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size() < b.size();
        });
        for(auto it:words) cout<<it<<" ";
        int n = words.size();
        vector<int> dp(n,1);
        int ans = 1;

        for(int i = 0;i<n;i++){
            for(int prev = 0;prev < i;prev++){
                if(match(words[i],words[prev])){
                    // cout<<words[i]<<" ";
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};