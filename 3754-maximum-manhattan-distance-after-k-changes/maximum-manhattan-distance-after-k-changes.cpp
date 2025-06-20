class Solution {
public:
    int maxDistance(string s, int k) {
        int cnn=0,cns=0,cne=0,cnw=0;
        int ans=0;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='N') cnn++;
            else if(s[i]=='S') cns++;
            else if(s[i]=='E') cne++;
            else cnw++;
            int t=min(k,min(cnn,cns)+min(cne,cnw));
            ans=max(ans,abs(cnn-cns)+abs(cne-cnw)+2*t);
        }
        return ans;
    }
};