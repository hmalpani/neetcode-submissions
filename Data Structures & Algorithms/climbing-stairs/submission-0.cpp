class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n,0);
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int n1 = 1, n2 = 2;
        for (int i=2; i<n; ++i) {
            int temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
        return n2;

    }
};
