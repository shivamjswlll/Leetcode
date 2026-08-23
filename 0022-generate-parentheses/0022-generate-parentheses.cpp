class Solution {
    void solve(int open,int close,string temp,int n,vector<string> &ans){
        if(close > open || open > n || close > n) return;
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back('(');
        solve(open+1,close,temp,n,ans);
        temp.pop_back();

        temp.push_back(')');
        solve(open,close+1,temp,n,ans);
        temp.pop_back();
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 1;
        int close = 0;

        solve(0,0,"",n,ans);

        return ans;
    }
};