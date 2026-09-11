class Solution {
private:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

    bool dfs(int course) {
        if (visited.contains(course)) {
            return false;
        }
        if (adj[course].size() == 0) {
            return true;
        }

        visited.insert(course);
        for (int c: adj[course]) {
            if (!dfs(c)) {
                return false;
            }
        }
        visited.erase(course);
        adj[course].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            adj[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int c = 0; c < numCourses; ++c) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }
};
