class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> T;
        for (int i=0; i<nums.size(); ++i) {
            T.push_back({nums[i], i});
        }
        sort(T.begin(), T.end());
        int i=0, j=nums.size()-1;
        while (i<j) {
            if (T[i].first + T[j].first == target) {
                return {min(T[i].second, T[j].second), max(T[i].second, T[j].second)};
            } else if (T[i].first + T[j].first < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {};
    }
};
