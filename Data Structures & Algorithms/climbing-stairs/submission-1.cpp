class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int cur = 2, prev = 1;
        for (int i = 3; i <= n; ++i) {
            int temp = cur + prev;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};
