class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=(int)status.size();
        vector<int> found(n,0);
        queue<int> q;
        for(int i=0;i<(int)initialBoxes.size();i++)
        {
            int u=initialBoxes[i];
            found[u]=1;
            if(status[u]) q.push(u);
        }
        int ans=0;
        while((int)q.size())
        {
            int u=q.front();
            q.pop();
            if(!candies[u]) continue;
            ans+=candies[u];
            candies[u]=0;
            for(int i=0;i<(int)keys[u].size();i++)
            {
                int v=keys[u][i];
                status[v]=1;
                if(status[v]&&found[v]) q.push(v);
            }
            for(int i=0;i<(int)containedBoxes[u].size();i++)
            {
                int v=containedBoxes[u][i];
                found[v]=1;
                if(status[v]&&found[v]) q.push(v);
            }
        }
        return ans;
    }
};