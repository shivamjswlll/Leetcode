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
    bool solve(TreeNode* root,long long mx, long long mn){
        if(root == NULL) return true;

        if(root->val >= mx || root->val <= mn ) return false;

        bool left = solve(root->left,root->val,mn);
        bool right = solve(root->right,mx,root->val);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {

        if(root ->left == NULL && root->right == NULL) return true;

        return solve(root,(long long)INT_MAX+1,(long long)INT_MIN-1);
    }
};