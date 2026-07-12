class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& pre: prerequisites) {
            indegree[pre[1]]++;
            adj[pre[0]].push_back(pre[1]);
        }
        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int total = 0;
        vector<int> ans;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ++total;
            ans.push_back(n);
            for (int dep: adj[n]) {
                indegree[dep]--;
                if (indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if (total == numCourses) return ans;
        return {};
    }
};
