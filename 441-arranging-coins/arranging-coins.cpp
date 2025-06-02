class Solution {
public:
    int arrangeCoins(long long n) {
        return (long long)((1+sqrt(1+8*n))/2)-1;
    }
};