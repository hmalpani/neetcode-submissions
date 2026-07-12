class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        for (int i=1; i<n-1; ++i) {
            left[i] = max (left[i-1], height[i-1]);
            right[n-i-1] = max(right[n-i], height[n-i]);
        }
        int ans=0;
        for (int i=1; i<n-1; ++i) {
            if (left[i] <= height[i] || right[i]<= height[i]) continue;
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};
