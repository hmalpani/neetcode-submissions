class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int maxarea = 0;
        while (l<r) {
            int temp = (r-l) * (heights[l] < heights[r] ? heights[l] : heights[r]);
            if (maxarea < temp) {
                maxarea = temp;
            }
            if (heights[l] < heights[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return maxarea;
    }
};
