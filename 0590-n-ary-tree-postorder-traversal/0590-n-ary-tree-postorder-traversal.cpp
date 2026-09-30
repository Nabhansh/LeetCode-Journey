class Solution {
public:

    void solve(vector<int>& ans, Node* root){
        if(root == nullptr){
            return;
        }

        int n = root->children.size();

        // Visit all children first
        for(int i = 0; i < n; i++){
            solve(ans, root->children[i]);
        }

        // Visit root after all children
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;

        solve(ans, root);

        return ans;
    }
};