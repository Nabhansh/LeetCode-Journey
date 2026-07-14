bool mirror(struct TreeNode* right, struct TreeNode* left, int x, int y, struct TreeNode* pright, struct TreeNode* pleft)
{
    if (!right || !left)
        return (false);
    if (pright != pleft && ((right->val == x && left->val == y) || (right->val == y && left->val == x)))
        return (true);
    return (mirror(right->right, left->left, x, y, right, left) || mirror(right->left, left->right, x, y, right, left) || mirror(right->right, left->right, x, y, right, left) || mirror(right->left, left->left, x, y, right, left) || mirror(right->right, right->left, x, y, right, right) || mirror(right->right, right->right, x, y, right, right) || mirror(left->left, left->right, x, y, left, left) || mirror(left->left, left->left, x, y, left, left));
}

bool isCousins(struct TreeNode* root, int x, int y)
{
    struct TreeNode* right;
    struct TreeNode* left;
    if (!root)
        return (false);
    right = root->right;
    left = root->left;
    return (mirror(right, left, x, y, root, root));
}