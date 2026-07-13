class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; ++i) {
            prefix[i] = max(prefix[i - 1], height[i - 1]);
            suffix[n - 1 - i] = max(suffix[n - i], height[n - i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            int temp = min(prefix[i], suffix[i]) - height[i];
            ans = ans + (temp > 0 ? temp : 0);
        }
        return ans;
    }
};
