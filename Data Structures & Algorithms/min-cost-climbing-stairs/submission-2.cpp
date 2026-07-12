class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2) return min(cost[0], cost[1]);
        int cost1 = cost[0], cost2 = cost[1];
        for (int i=2; i<n; ++i) {
            int temp = cost[i] + min(cost1, cost2);
            cost1 = cost2;
            cost2 = temp;
        }
        return min(cost2, cost1);
    }
};
