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
    void solve(TreeNode* root,int target,TreeNode* prv,int dir){
        if(root == NULL) return;

        if(!root->left && !root->right && root->val == target){
            if(dir == 0){
                prv -> left = NULL;
            }else if(dir == 1){
                prv->right = NULL;
            }
            
        }
        solve(root->left,target,root,0);
        solve(root->right,target,root,1);
        if(!root->left && !root->right && root->val == target){
            if(dir == 0){
                prv -> left = NULL;
            }else if(dir == 1){
                prv->right = NULL;
            }
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target,NULL,-1);
        if(!root->left && !root->right && root->val == target) return NULL;
        return root;
    }
};