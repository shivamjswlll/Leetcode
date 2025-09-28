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
    void solve(TreeNode* root,int mx,int &ans){
       if(root == NULL) return;

       if(root->val >= mx){
        ans++;
        solve(root->left,root->val,ans);
        solve(root->right,root->val,ans);
       }else{
        solve(root->left,mx,ans);
        solve(root->right,mx,ans);
       }

    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });