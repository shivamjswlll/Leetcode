/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root,int k ,int &ans,int &cnt){
        if(root == NULL) return;

        solve(root->left,k,ans,cnt);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right,k,ans,cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;
        solve(root,k,ans,cnt);
        return ans;
    }
};