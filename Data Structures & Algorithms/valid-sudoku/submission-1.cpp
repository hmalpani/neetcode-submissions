class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int r = 0; r < 9; ++r) {
            unordered_set<int> s;
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (s.contains(board[r][c])) {
                    return false;
                }
                s.insert(board[r][c]);
            }
        }
        // Check cols
        for (int c = 0; c < 9; ++c) {
            unordered_set<int> s;
            for (int r = 0; r < 9; ++r) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (s.contains(board[r][c])) {
                    return false;
                }
                s.insert(board[r][c]);
            }
        }
        for (int sq = 0; sq < 9; ++sq) {
            unordered_set<int> s;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int r = (sq / 3) * 3 + i;
                    int c = (sq % 3) * 3 + j;
                    if (board[r][c] == '.') {
                        continue;
                    }
                    if (s.contains(board[r][c])) {
                        return false;
                    }
                    s.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
