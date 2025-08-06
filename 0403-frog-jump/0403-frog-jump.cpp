class Solution {
    map<int,int> mp;
    bool solve(int idx,int jump,vector<int> &stones,unordered_map<int,unordered_map<int,bool>> &dp){
        if(idx >= stones.size()) return false;
        if(idx == stones.size()-1) return true;

        if(dp[idx].find(jump) != dp[idx].end()) return dp[idx][jump];

        int a = stones[idx] + jump + 1;
        int b = stones[idx] + jump ;
        int c = stones[idx] + jump - 1;

        bool jumps1= false;
        bool jumps2 = false;
        bool jumps3 = false;

        if(mp.find(a) != mp.end()){
            int nextidx = mp[a];
            jumps1 = solve(nextidx,a-stones[idx],stones,dp);
        }
        if(jump != 0 && mp.find(b) != mp.end()){
            int nextidx = mp[b];
            jumps2 = solve(nextidx,b-stones[idx],stones,dp);
        }
        if(jump > 1 && mp.find(c) != mp.end()){
            int nextidx = mp[c];
            jumps3 = solve(nextidx,c-stones[idx],stones,dp);
        }
        return dp[idx][jump] = jumps1 || jumps2 || jumps3;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int mx = stones[stones.size()-1];
        for(int i = 0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
       unordered_map<int,unordered_map<int,bool>> dp;
       return solve(0,0,stones,dp);
    }
};