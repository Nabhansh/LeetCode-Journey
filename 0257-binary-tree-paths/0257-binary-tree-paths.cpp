class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path) {
            if (!node) return;

            path += to_string(node->val);

            if (!node->left && !node->right) {
                ans.push_back(path);
                return;
            }

            path += "->";

            dfs(node->left, path);
            dfs(node->right, path);
        };

        dfs(root, "");
        return ans;
    }
};