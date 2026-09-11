class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 1);
        vector<vector<int>> adj(n + 1);

        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]] += 1;
            indegree[edge[1]] += 1;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            indegree[node] -= 1;
            for (int neighbor: adj[node]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }
        for (int i = edges.size() - 1; i >= 0; --i) {
            if (indegree[edges[i][0]] == 2 && indegree[edges[i][1]] == 2) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};
