class Solution {
public:
    unordered_set<int> s;

    bool dfs(TreeNode* root, int k) {
        if (!root)
            return false;

        if (s.count(k - root->val))
            return true;

        s.insert(root->val);

        return dfs(root->left, k) || dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};