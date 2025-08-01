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
    TreeNode* solve(vector<int> &preorder,int &it,int ub){
        if(it >= preorder.size() || preorder[it] > ub) return NULL;
        TreeNode* root = new TreeNode(preorder[it++]);
        root->left = solve(preorder,it,root->val);
        root->right = solve(preorder,it,ub);
        return root;
    }
public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder,i,INT_MAX);
    }
};