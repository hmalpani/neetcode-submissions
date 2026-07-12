class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (auto a: piles) {
            r = max(r, a);
        }
        while (l <= r) {
            int mid = (l + r) / 2;
            int hours = 0;
            for (int i = 0; i < piles.size(); ++i) {
                hours += (piles[i] + mid - 1) / mid;
            }
            if (hours <= h) {
                r = mid - 1;
            } else if (hours > h) {
                l = mid + 1;
            }
        }
        return l;
    }
};
