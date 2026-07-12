class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                if (rows[r].contains(board[r][c])) {
                    return false;
                }
                if (cols[c].contains(board[r][c])) {
                    return false;
                }
                pair<int, int> sq_key = {r / 3, c / 3};
                if (squares[sq_key].contains(board[r][c])) {
                    return false;
                }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[sq_key].insert(board[r][c]);
            }
        }
        return true;
    }
};
