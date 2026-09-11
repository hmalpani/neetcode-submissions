class Solution {
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        ocean[r][c] = true;

        int dirs[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && heights[nr][nc] >= heights[r][c] && !ocean[nr][nc]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
