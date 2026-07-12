class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for (int i=n-1; i>=0; --i) {
            if (i == n-1) {
                digits[i] += 1;
            }
            int temp = digits[i] + carry;
            digits[i] = temp%10;
            carry = temp/10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
