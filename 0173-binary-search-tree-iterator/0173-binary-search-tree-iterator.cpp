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
class BSTIterator {
    vector<int> inorder;
    int i;
    int n;
    void solve(vector<int> &inorder,TreeNode* root){
        if(root == NULL) return;

        solve(inorder,root->left);
        inorder.push_back(root->val);
        solve(inorder,root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        solve(inorder,root);
        i = 0;
        n = inorder.size();
    }
    
    int next() {
        i++;
       return inorder[i-1];
    }
    
    bool hasNext() {
        if(i >= n) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */