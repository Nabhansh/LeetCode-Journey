int dfs(struct TreeNode* root, int cur) {
    if (!root) return 0;

    cur = (cur << 1) | root->val;

    if (!root->left && !root->right)
        return cur;

    return dfs(root->left, cur) + dfs(root->right, cur);
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);
}