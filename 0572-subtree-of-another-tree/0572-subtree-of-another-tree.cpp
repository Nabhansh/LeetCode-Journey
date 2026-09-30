class Solution {
public:
    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;

        if (!a || !b || a->val != b->val)
            return false;

        return same(a->left, b->left) && same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;

        if (!root)
            return false;

        if (same(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};