class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        vector<vector<int>> adj(n);
        for (auto& edg: edges) {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        if (!dfs(0, -1, visited, adj)) return false;
        return visited.size()==n;
    }

    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>>& adj) {
        if (visited.count(node)) return false;
        visited.insert(node);
        for (auto adj_node: adj[node]) {
            if (adj_node == parent) continue;
            if (!dfs(adj_node, node, visited, adj)) return false;
        }
        return true;
    }
};
