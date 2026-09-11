class Solution {
    int ans;
    vector<vector<bool>> visited;

    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        visited[r][c] = true;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !visited[nx][ny]) {
                bfs(nx, ny, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        int m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
