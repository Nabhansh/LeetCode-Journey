class Solution {
public:
    int ans = 0;

    int sum(TreeNode* root) {
        if (!root)
            return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        ans += abs(left - right);

        return root->val + left + right;
    }

    int findTilt(TreeNode* root) {
        sum(root);
        return ans;
    }
};