class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        for (int i=0; i<rows; ++i) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if (board[i][cols-1] == 'O') {
                dfs(i, cols-1, board);
            }
        }
        for (int i=0; i<cols; ++i) {
            if (board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if (board[rows-1][i] == 'O') {
                dfs(rows-1, i, board);
            }
        }
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void dfs(int row, int col, vector<vector<char>>& board) {
        board[row][col] = '#';
        for (auto dir: dirs) {
            int r = row + dir.first;
            int c = col + dir.second;
            if (r>=0 && r<board.size() && c>=0 && c<board[0].size()) {
                if (board[r][c] == 'O') {
                    dfs(r, c, board);
                }
            }
        }
    }
};
