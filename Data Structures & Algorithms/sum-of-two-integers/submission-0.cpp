class Solution {
public:
    int getSum(int a, int b) {
        int sum = a, carry = b;
        while (carry) {
            int temp = sum ^ carry;
            carry = (sum & carry)<<1;
            sum = temp;
        }
        return sum;
    }
};
