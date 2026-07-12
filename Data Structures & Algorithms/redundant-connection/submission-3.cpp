class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), rank(n+1, 1);
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
        vector<int> ans;
        for (auto edge: edges) {
            if (!Union(parent, rank, edge[0], edge[1])) {
                ans = edge;
            }
        }
        if (ans.size()) return ans;
        return {};
    }
private:
    int find(vector<int>& parent, int n) {
        int p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    bool Union(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = find(parent, n1);
        int p2 = find(parent, n2);
        if (p1 == p2) {
            return false;
        }
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
