class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            indegree[prerequisites[i][0]] += 1;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int cur_course = q.front();
            q.pop();
            ans.push_back(cur_course);

            for (int dependent: adj[cur_course]) {
                indegree[dependent] -= 1;
                if (indegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }
        return (ans.size() == numCourses) ? ans : vector<int>{};
    }
};
