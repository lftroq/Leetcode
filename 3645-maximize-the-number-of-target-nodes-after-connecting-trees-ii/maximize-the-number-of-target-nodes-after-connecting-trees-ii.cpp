class Solution {
public:
    vector<int> graph[100000];
    int h[100000],cn=0;
    void dfs(int u,int p)
    {
        cn+=h[u];
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(v==p) continue;
            h[v]=h[u]^1;
            dfs(v,u);
        }
    }
    int dfs2(int u,int p,int c)
    {
        int ans=c;
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(v==p) continue;
            ans+=dfs2(v,u,c^1);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=(int)edges1.size()+1;
        int m=(int)edges2.size()+1;
        for(int i=0;i<m-1;i++)
        {
            graph[edges2[i][0]].push_back(edges2[i][1]);
            graph[edges2[i][1]].push_back(edges2[i][0]);
        }
        int c=dfs2(0,0,1);
        c=max(c,m-c);
        for(int i=0;i<m;i++) graph[i].clear();
        for(int i=0;i<n-1;i++)
        {
            graph[edges1[i][0]].push_back(edges1[i][1]);
            graph[edges1[i][1]].push_back(edges1[i][0]);
        }
        dfs(0,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(h[i]) ans.push_back(cn+c);
            else ans.push_back(n-cn+c);
        }
        return ans;
    }
};