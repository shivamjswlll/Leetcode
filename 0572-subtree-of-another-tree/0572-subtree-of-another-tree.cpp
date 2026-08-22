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
    bool solve(TreeNode* root,TreeNode* sRoot){
        if(root == NULL && sRoot == NULL) return true;

        if(root == NULL || sRoot == NULL) return false;

        if(root->val == sRoot->val){
            return solve(root->left,sRoot->left) && solve(root->right,sRoot->right);
        }

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL) return false;
        bool same = false;

        if(root->val == subRoot->val){
            same =  solve(root,subRoot);
        }

        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);

        return left || right ||same;
    }
};