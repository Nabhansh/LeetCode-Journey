class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        long long total = 0;
        for (int v : values)
            total += v;

        return total - dfs(0, -1, graph, values);
    }

private:
    long long dfs(int u, int parent, vector<vector<int>>& graph, vector<int>& values) {
        // Leaf node (except root)
        if (u != 0 && graph[u].size() == 1)
            return values[u];

        long long childCost = 0;

        for (int v : graph[u]) {
            if (v != parent)
                childCost += dfs(v, u, graph, values);
        }

        return min((long long)values[u], childCost);
    }
};