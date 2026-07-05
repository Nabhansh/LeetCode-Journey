int prev, ans;

void inorder(struct TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (prev != -1 && root->val - prev < ans)
        ans = root->val - prev;
    prev = root->val;

    inorder(root->right);
}

int minDiffInBST(struct TreeNode* root) {
    prev = -1;
    ans = INT_MAX;
    inorder(root);
    return ans;
}