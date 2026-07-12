class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = 0, fresh=0;

        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) ++fresh;
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!q.empty()) {
            int l = q.size();
            bool rotted = false;
            for (int i=0; i<l; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto dir: dirs) {
                    int r = row + dir[0];
                    int c = col + dir[1];
                    if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) {
                        continue;
                    }
                    if (grid[r][c] == 1) {
                        rotted = true;
                        --fresh;
                        grid[r][c] = 2;
                        q.push({r,c});
                    }
                }
            }
            if (rotted) ++time;
        }
        return fresh==0?time:-1;
    }
};
