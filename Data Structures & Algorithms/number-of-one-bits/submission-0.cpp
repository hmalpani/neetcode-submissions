class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            ans += ((1<<i) & n) != 0 ? 1 : 0;
        }
        return ans;
    }
};
