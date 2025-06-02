const int N=1e5+5;

class Solution {
public:
    int ne[N];
    int h1[N],h2[N];
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=(int)edges.size();
        for(int i=0;i<n;i++) ne[i]=edges[i];
        int u=node1;
        h1[u]=1;
        while(ne[u]!=-1&&!h1[ne[u]])
        {
            h1[ne[u]]=h1[u]+1;
            u=ne[u];
        }
        u=node2;
        h2[u]=1;
        while(ne[u]!=-1&&!h2[ne[u]])
        {
            h2[ne[u]]=h2[u]+1;
            u=ne[u];
        }
        int ans=n;
        h1[n]=h2[n]=1e9;
        for(int i=0;i<n;i++)
        {
            if(h1[i]==0||h2[i]==0) continue;
            if(max(h1[ans],h2[ans])>max(h1[i],h2[i])) ans=i;
        }
        if(ans==n) ans=-1;
        return ans;
    }
};