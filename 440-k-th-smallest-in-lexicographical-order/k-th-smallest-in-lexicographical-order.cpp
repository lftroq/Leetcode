class Solution {
public:
    int findKthNumber(int n, int k) {
        k--;
        int ans=1;
        while(k)
        {
            int temp=calc(n, ans);
            if(temp<=k)
            {
                ans++;
                k-=temp;
            }
            else 
            {
                ans*=10;
                k--;
            }
        }
        return ans;
    }
    int calc(int n,long long prefix1)
    {
        long long prefix2=prefix1+1;
        int ans=0;
        while(prefix1<=n)
        {
            ans+=min((n+1ll),prefix2)-prefix1;
            prefix1*=10;prefix2*=10;
        }
        return ans;
    }
};