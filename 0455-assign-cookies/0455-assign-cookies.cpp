class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int students = g.size();
        int cookie = s.size();
        int ans = 0;

        int st = students-1;
        int c = cookie-1;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(st>= 0 && c >= 0){
            if(g[st] <= s[c]){
                st--;c--;ans++;
            }
            else{
                st--;
            }
        }
        return ans;
    }
};