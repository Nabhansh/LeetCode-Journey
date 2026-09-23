class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;

        int ans = 0;

        if (root->left && !root->left->left && !root->left->right)
            ans += root->left->val;

        ans += sumOfLeftLeaves(root->left);
        ans += sumOfLeftLeaves(root->right);

        return ans;
    }
};