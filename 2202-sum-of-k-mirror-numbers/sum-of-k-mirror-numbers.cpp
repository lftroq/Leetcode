class Solution {
public:
    bool ispa(long long x,int k)
    {
        vector<int> v;
        while(x)
        {
            v.push_back(x%k);
            x/=k;
        }
        for(int i=0;i<(int)v.size();i++) if(v[i]!=v[v.size()-i-1]) return false;
        return true;
    }
    long long kMirror(int k, int n) {
        int l=1,cn=0;
        long long ans=0;
        while(cn<n)
        {
            int r=l*10;
            for(int op=0;op<2;op++)
            {
                for(int i=l;i<r&&cn<n;i++)
                {
                    long long temp=i;
                    int x=(op==0?i/10:i);
                    while(x)
                    {
                        temp=temp*10+x%10;
                        x/=10;
                    }
                    if(ispa(temp,k))
                    {
                        ans+=temp;
                        cn++;
                    }
                }
            }
            l=r;
        }
        return ans;
    }
};