class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i=0; i<32; ++i) {
            int temp = n%2;
            n/=2;
            ans = ans*2 + temp;
        }
        return ans;
    }
};
