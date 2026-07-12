class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        bool neg = (n<0);
        double ans = 1;
        if (neg) {
            ans = myPow(x, -n);
            return 1/ans;
        }
        if (n==1) return x;
        ans = myPow(x,n/2);
end:
        ans = n%2?(ans*ans*x):(ans*ans);
        if (neg) ans = 1/ans;
        return ans;
    }
};
