class Solution {
public:
    bool check(int x) {
        if(!x) return false;
        while(x) {
            if(!(x%10)) return false;
            x/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=0;i<=n;i++) if(check(i)&&check(n-i)) return {i,n-i};
        return {-1,-1};
    }
};