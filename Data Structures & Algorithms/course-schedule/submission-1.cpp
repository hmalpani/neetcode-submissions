class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ++total;
            for (int dep: adj[n]) {
                indegree[dep]--;
                if (indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        }
        return total==numCourses;
    }
};
