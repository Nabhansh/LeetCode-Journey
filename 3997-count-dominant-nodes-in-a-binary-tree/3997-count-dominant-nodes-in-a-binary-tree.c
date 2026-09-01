int ans;

int dfs(struct TreeNode* root) {
    if (root == NULL)
        return -2147483648;

    int left = dfs(root->left);
    int right = dfs(root->right);

    int mx = root->val;

    if (left > mx)
        mx = left;

    if (right > mx)
        mx = right;

    if (root->val == mx)
        ans++;

    return mx;
}

int countDominantNodes(struct TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
}