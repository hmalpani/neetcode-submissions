class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix.size()-1;
        while (i<=j) {
            int mid = (i+j)/2;
            if (matrix[mid][0]<=target) {
                i=mid+1;
            } else {
                j=mid-1;
            }
        }
        int row = j;
        if (row < 0) return false;
        i=0; j=matrix[row].size()-1;
        while (i<=j) {
            int mid = (i+j)/2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                i=mid+1;
            } else {
                j=mid-1;
            }
        }
        return false;
    }
};
