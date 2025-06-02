class Solution {
public:
    vector<int> graph[1005];
    int dfs(int u,int p,int cn)
    {
        if(!cn) return 0;
        int ans=1;
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(v==p) continue;
            ans+=dfs(v,u,cn-1);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=(int)edges2.size()+1,s=0;
        for(int i=0;i<(int)edges2.size();i++) 
        {
            graph[edges2[i][0]].push_back(edges2[i][1]);
            graph[edges2[i][1]].push_back(edges2[i][0]);
        }
        for(int i=0;i<n;i++) s=max(s,dfs(i,i,k));
        for(int i=0;i<n;i++) graph[i].clear();
        n=(int)edges1.size()+1;
        for(int i=0;i<(int)edges1.size();i++)
        {
            graph[edges1[i][0]].push_back(edges1[i][1]);
            graph[edges1[i][1]].push_back(edges1[i][0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(s+dfs(i,i,k+1));
        return ans;
    }
};