class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size() + 1, 0);
        int cur_min_1 = 0, cur_min_2 = 0;
        for (int i = 2; i < cost.size() + 1; ++i) {
            int temp = min(cur_min_1 + cost[i - 1], cur_min_2 + cost[i - 2]);
            cur_min_2 = cur_min_1;
            cur_min_1 = temp;
        }
        return cur_min_1;
    }
};
