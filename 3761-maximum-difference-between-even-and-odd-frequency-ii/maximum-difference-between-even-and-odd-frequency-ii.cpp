class Solution {
public:
    const int INF=1e9;
    int get(int cna,int cnb)
    {
        return ((cna&1)<<1)|(cnb&1);
    }
    int maxDifference(string s, int k) {
        int n=(int)s.size(),ans=-INF;
        for(char a='0';a<='4';a++) for(char b='0';b<='4';b++)
        {
            if(a==b) continue;
            int mi[4]={INF,INF,INF,INF};
            int cna,cnb,pra,prb;
            cna=cnb=pra=prb=0;
            int j=-1;
            for(int i=0;i<n;i++)
            {
                cna+=(s[i]==a);
                cnb+=(s[i]==b);
                while(i-j>=k&&cnb-prb>=2)
                {
                    int left=get(pra,prb);
                    mi[left]=min(mi[left],pra-prb);
                    j++;
                    pra+=(s[j]==a);
                    prb+=(s[j]==b);
                }
                int right=get(cna,cnb);
                if(mi[right^0b10]!=INF) ans=max(ans,cna-cnb-mi[right^0b10]);
            }
        }
        return ans;
    }
};