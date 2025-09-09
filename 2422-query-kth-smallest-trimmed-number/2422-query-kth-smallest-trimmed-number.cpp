class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int k = queries[i][0];
            int trim = queries[i][1];

            // Use string in the pair
            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            for (int j = 0; j < nums.size(); j++) {
                string trimmed = nums[j].substr(nums[j].size() - trim);
                pq.push({trimmed, j});
            }

            // Pop k-1 times to find k-th smallest
            while (!pq.empty() && k > 1) {
                pq.pop();
                k--;
            }
            ans[i] = pq.top().second;
        }
        return ans;
    }
};
