class Solution {
public:
    int reverse(int x) {
        string a = to_string(abs(x));
        std::reverse(a.begin(), a.end());
        long long temp = stoll(a);
        if (x<0) temp*=-1;
        if (temp < -(1LL << 31) || temp > (1LL <<31) - 1) return 0;
        return static_cast<int>(temp);
    }
};
