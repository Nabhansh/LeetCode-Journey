class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if (root->val == 2)
            return left || right;

        return left && right;
    }
};