class Solution {
    void dfs(int node, vector<unordered_set<int>>& adj, unordered_set<int>& visited) {
        if (visited.contains(node)) {
            return;
        }
        visited.insert(node);
        for (int neighbor: adj[node]) {
            if (!visited.contains(neighbor)) {
                dfs(neighbor, adj, visited);
            }
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }

        vector<int> ans;
        for (int i = edges.size() - 1; i >= 0; --i) {
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);
            unordered_set<int> visited;
            dfs(1, adj, visited);
            if (visited.size() == n) {
                return edges[i];
            }
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        return {};
    }
};
