class Solution {
    TreeNode* solve(TreeNode* root, int key) {
        if (root == NULL) return nullptr;

        if (root->left && root->left->val == key) return root;
        if (root->right && root->right->val == key) return root;

        if (key < root->val) return solve(root->left, key);
        return solve(root->right, key);
    }

    TreeNode* solve1(TreeNode* node) {
        // Find rightmost node in the given subtree
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // If root itself is the node to delete
        if (root->val == key) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Two children → find inorder predecessor
            TreeNode* pred = solve1(root->left);
            root->val = pred->val;
            root->left = deleteNode(root->left, pred->val);
            return root;
        }

        // Find parent node of the key
        TreeNode* node = solve(root, key);
        if (!node) return root; // Key not found → return unchanged tree

        // Check if key is on left or right side
        TreeNode* target = nullptr;
        bool isLeft = false;
        if (node->left && node->left->val == key) {
            target = node->left;
            isLeft = true;
        } else if (node->right && node->right->val == key) {
            target = node->right;
        }

        if (!target) return root; // Key not found

        // Case 1: No children
        if (!target->left && !target->right) {
            if (isLeft) node->left = nullptr;
            else node->right = nullptr;
        }
        // Case 2: One child
        else if (!target->left || !target->right) {
            TreeNode* child = target->left ? target->left : target->right;
            if (isLeft) node->left = child;
            else node->right = child;
        }
        // Case 3: Two children
        else {
            TreeNode* pred = solve1(target->left);
            int val = pred->val;
            deleteNode(root, val); // Delete predecessor from tree
            target->val = val;
        }

        return root;
    }
};
