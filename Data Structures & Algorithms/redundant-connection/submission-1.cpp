class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> adj(n+1);
        for (int i=0; i<n; ++i) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            adj[edges[i][0]].erase(edges[i][1]);
            adj[edges[i][1]].erase(edges[i][0]);
            unordered_set<int> visited;
            dfs(1, adj, visited);
            if (visited.size() == n) {
                ans = edges[i];
            }
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        return ans;
    }
    void dfs(int node, vector<unordered_set<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(node)) {
            return;
        }
        visited.insert(node);
        for (auto& adj_node: adj[node]) {
            if (visited.count(adj_node) == 0) {
                dfs(adj_node, adj, visited);
            }
        }
    }
};
