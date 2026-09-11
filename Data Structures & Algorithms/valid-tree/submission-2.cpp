class Solution {
    vector<bool> visited;
    
    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>>& adj) {
        if (visited.contains(node)) {
            return false;
        }
        visited.insert(node);
        for (int n: adj[node]) {
            if (n == parent) {
                continue;
            }
            if (!dfs(n, node, visited, adj)) {
                return false;
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if (!dfs(0, -1, visited, adj)) {
            return false;
        }
        return visited.size() == n;
    }
};
