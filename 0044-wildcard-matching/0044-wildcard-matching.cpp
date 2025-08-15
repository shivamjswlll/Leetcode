class Solution {
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            // '*' matches zero chars OR matches one char and stays in '*'
            return dp[i][j] = solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(n1 - 1, n2 - 1, s, p, dp);
    }
};
