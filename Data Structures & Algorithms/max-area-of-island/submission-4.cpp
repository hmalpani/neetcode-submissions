class Solution {
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        int connected = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                connected += bfs(nx, ny, grid, visited);
            }
        }
        return 1 + connected;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();

        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans = max(ans, bfs(i, j, grid, visited));
                }
            }
        }
        return ans;
    }
};
