class Solution {
    vector<bool> visited;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int cycleStart;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited.resize(n + 1);
        cycleStart = -1;
        dfs(1, -1);

        for (int i = edges.size() - 1; i >= 0; --i) {
            if (cycle.contains(edges[i][0]) && cycle.contains(edges[i][1])) {
                return edges[i];
            }
        }
        return {};
    }
private:
    bool dfs(int node, int parent) {
        if (visited[node]) {
            cycleStart = node;
            return true;
        }
        visited[node] = true;
        for (int neighbor: adj[node]) {
            if (neighbor != parent) {
                if (dfs(neighbor, node)) {
                    if (cycleStart != -1) {
                        cycle.insert(node);
                    }
                    if (node == cycleStart) {
                        cycleStart = -1;
                    }
                    return true;
                }
            }
        }
        return false;
    }
};
