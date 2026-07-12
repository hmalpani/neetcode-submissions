class Solution {
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int i=0; i<rows; ++i) {
            dfs(i, 0, pacific, heights);
            dfs(i, cols-1, atlantic, heights);
        }
        for (int i=0; i<cols; ++i) {
            dfs(0, i, pacific, heights);
            dfs(rows-1, i, atlantic, heights);
        }
        vector<vector<int>> ans;
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[row][col] = true;
        for (auto dir: dirs) {
            int r = dir.first + row;
            int c = dir.second + col;
            if (r>=0 && r<heights.size() && c>=0 && c<heights[0].size()) {
                if (!ocean[r][c] && heights[r][c]>=heights[row][col]) {
                    dfs(r, c, ocean, heights);
                }
            }
        }
    }
};
