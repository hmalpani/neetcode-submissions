class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (visited[i]) continue;
            dfs(i, visited, adj);
            ++ans;
        }
        return ans;
    }

    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        for (int adj_node: adj[node]) {
            if (!visited[adj_node]) {
                dfs(adj_node, visited, adj);
            }
        }
    }
};
