class Solution {
public:
    vector<int> ans;
    int prev = 0;
    int count = 0;
    int maxCount = 0;
    bool first = true;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        if (first || root->val != prev) {
            count = 1;
            prev = root->val;
            first = false;
        } else {
            count++;
        }

        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } else if (count == maxCount) {
            ans.push_back(root->val);
        }

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};