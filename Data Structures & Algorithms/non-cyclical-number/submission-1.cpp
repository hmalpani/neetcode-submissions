class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> visit;
        while (n!=1 && visit[n] != 1) {
            int temp = 0;
            // x=n;
            visit[n] = 1;
            while (n) {
                temp += (n%10)*(n%10);
                n/=10;
            }
            n = temp;
        }
        if (n == 1) return true;
        return false;
    }
};
