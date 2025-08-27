class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int n = s.size();
        int ans = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            mp[s[r]]++;
            int mx = 0;
            for (auto it : mp) {
                mx = max(mx, it.second);
            }

            if (mx + k >= r - l + 1) {
                ans = max(ans, r - l + 1);
                r++;
            } else {
                while (l <= r) {
                    mp[s[l]]--;
                    l++;

                    mx = 0;
                    for (auto it : mp) {
                        mx = max(mx, it.second);
                    }

                    if (mx + k >= r - l + 1) break;
                }
                r++;
            }
        }
        return ans;
    }
};
