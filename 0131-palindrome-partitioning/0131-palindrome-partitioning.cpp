class Solution {
    private:
    bool isPalindrome(string tmp){
        if(tmp.size() == 1) return true;

        int i = 0;
        int j = tmp.size()-1;

        while(i<= j){
            if(tmp[i] != tmp[j]) return false;
            i++,j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> &temp,vector<vector<string>> &result){
        if(idx == s.size()){
            result.push_back(temp);
            return;
        }
        string tmp = "";
        for(int i = idx;i<s.size();i++){
            tmp += s[i];
            if(isPalindrome(tmp)){
                temp.push_back(tmp);
                solve(i+1,s,temp,result);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        solve(0,s,temp,result);
        return result;
    }

    
};