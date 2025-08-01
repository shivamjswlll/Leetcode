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
    bool solve(TreeNode* root,int k , map<int,int> &mp){
        if(root == NULL) return false;

        if(solve(root->left,k,mp)) return true;
        int fnd = k - root->val;
        if(mp.find(fnd) != mp.end()) return true;
        mp[root->val]++;
        if(solve(root->right,k,mp)) return true;

        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        return solve(root,k,mp);
    }
};