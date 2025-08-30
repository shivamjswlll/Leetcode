class Solution {
    unordered_map<TreeNode*, vector<int>> dp; 
    // dp[node][0] = max if we cannot rob this node
    // dp[node][1] = max if we can rob this node

    int solve(TreeNode* root, int k) {
        if (!root) return 0;

        if (!dp.count(root)) {
            dp[root] = vector<int>(2, -1); // initialize with -1
        }

        if (dp[root][k] != -1) return dp[root][k];

        int take = 0, notTake = 0;

        if (k == 1) { // can rob this node
            take = root->val + solve(root->left, 0) + solve(root->right, 0);
        }
        notTake = solve(root->left, 1) + solve(root->right, 1);

        return dp[root][k] = max(take, notTake);
    }

public:
    int rob(TreeNode* root) {
        return solve(root, 1);
    }
};
