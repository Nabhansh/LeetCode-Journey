void inorder(struct TreeNode* root, struct TreeNode** current) {
    if (root == NULL) {
        return;
    }

    struct TreeNode* right = root->right;

    inorder(root->left, current);

    root->left = NULL;
    (*current)->right = root;
    *current = root;

    inorder(right, current);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode dummy;
    dummy.val = 0;
    dummy.left = NULL;
    dummy.right = NULL;

    struct TreeNode* current = &dummy;

    inorder(root, &current);

    return dummy.right;
}