
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        function<bool(int)> dfs = [&](int node) {
            if (node == destination)
                return true;

            visited[node] = true;

            for (int next : adj[node]) {
                if (!visited[next]) {
                    if (dfs(next))
                        return true;
                }
            }

            return false;
        };

        return dfs(source);
    }
};
