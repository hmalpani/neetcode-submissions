class Solution {
public:
    int ans;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        // int count=0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // count++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return this->ans;
    }

    void bfs(int i, int j, vector<vector<int>> grid, vector<vector<bool>> &visited) {
        int x = 0;
        queue<pair<int, int>> q;
        q.push({i,j});
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            if (!visited[temp.first][temp.second]) ++x;
            visited[temp.first][temp.second] = true;
            q.pop();
            if (temp.first>0) {
                if (grid[temp.first-1][temp.second] == 1 && !visited[temp.first-1][temp.second]) {
                    q.push({temp.first-1, temp.second});
                }
            }
            if (temp.first<(grid.size()-1)) {
                if (grid[temp.first+1][temp.second] == 1 && !visited[temp.first+1][temp.second]) {
                    q.push({temp.first+1, temp.second});
                }
            }
            if (temp.second>0) {
                if (grid[temp.first][temp.second-1] == 1 && !visited[temp.first][temp.second-1]) {
                    q.push({temp.first, temp.second-1});
                }
            }
            if (temp.second<(grid[0].size()-1)) {
                if (grid[temp.first][temp.second+1] == 1 && !visited[temp.first][temp.second+1]) {
                    q.push({temp.first, temp.second+1});
                }
            }
        }
        if (x > this->ans) ans = x;
    }
};
