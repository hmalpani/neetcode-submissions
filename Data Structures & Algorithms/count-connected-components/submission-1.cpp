class Solution {
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int cur_node = q.front();
            q.pop();
            visited[cur_node] = true;
            for (int neighbor : adj[cur_node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                bfs(i, adj, visited);
            }
        }
        return ans;
    }
};
