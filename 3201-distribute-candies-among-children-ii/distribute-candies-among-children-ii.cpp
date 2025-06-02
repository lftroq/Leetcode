class Solution {
public:
    long long calc(int n)
    {
        return (n<0?0:1ll*(n+2)*(n+1)/2);
    }
    long long distributeCandies(int n, int limit) {
        return calc(n)-3*calc(n-limit-1)+3*calc(n-2*limit-2)-calc(n-3*limit-3);
    }
};