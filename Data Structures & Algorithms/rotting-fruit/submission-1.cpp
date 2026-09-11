class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total_fresh_oranges = 0;
        queue<pair<int, int>> bad_oranges;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    total_fresh_oranges++;
                } else if (grid[i][j] == 2) {
                    bad_oranges.push({i, j});
                }
            }
        }

        int ans = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (total_fresh_oranges > 0 && !bad_oranges.empty()) {            
            int rotten = bad_oranges.size();
            while (rotten > 0) {
                --rotten;
                int r = bad_oranges.front().first;
                int c = bad_oranges.front().second;
                bad_oranges.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = r + dx[i];
                    int ny = c + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        total_fresh_oranges--;
                        bad_oranges.push({nx, ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            ans++;
        }
        return total_fresh_oranges == 0 ? ans : -1;
    }
};
