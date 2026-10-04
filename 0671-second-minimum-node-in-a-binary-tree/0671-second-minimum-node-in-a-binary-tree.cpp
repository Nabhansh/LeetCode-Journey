class Solution {
public:
    long long first;
    long long second = LLONG_MAX;

    void dfs(TreeNode* root) {
        if (!root)
            return;

        if (root->val > first && root->val < second)
            second = root->val;

        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        first = root->val;
        dfs(root);

        return second == LLONG_MAX ? -1 : second;
    }
};