class Solution {
    unordered_map<int, vector<int>> map;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i=0; i<numCourses; ++i) {
            map[i] = {};
        }
        for (const auto& prereq: prerequisites) {
            map[prereq[0]].push_back(prereq[1]);
        }
        for (int i=0; i<numCourses; ++i) {
            if (!dfs(i)) return false;
        }
        return true;
    }

    bool dfs(int node) {
        if (visiting.count(node)) return false;
        if (map[node].empty()) return true;
        visiting.insert(node);
        for (int dep: map[node]) {
            if (!dfs(dep)) return false;
        }
        visiting.erase(node);
        map[node].clear();
        return true;
    }
};
