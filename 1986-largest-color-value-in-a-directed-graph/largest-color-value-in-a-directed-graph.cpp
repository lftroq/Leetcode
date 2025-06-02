const int N = 1e5 + 5;

class Solution {
public:
    int n;
    vector<int> graph[N], topo;
    char a[N];
    int rev[N], dp[N];
    bool vis[N];

    void toposort(int u) {
        vis[u] = 1;
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];
            if (!vis[v])
                toposort(v);
        }
        topo.push_back(u);
    }
    int calc(char c) {
        for (int i = 1; i <= n; i++)
            dp[i] = (a[i] == c);
        int ans = 0;
        for (int j = 0; j < (int)topo.size(); j++) {
            int u = topo[j];
            for (int i = 0; i < (int)graph[u].size(); i++) {
                int v = graph[u][i];
                dp[v] = max(dp[v], dp[u] + (a[v] == c));
            }
            ans = max(ans, dp[u]);
        }
        return ans;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = (int)colors.size();
        for (int i = 1; i <= n; i++)
            a[i] = colors[i - 1];
        for (int i = 0; i < (int)edges.size(); i++)
            graph[++edges[i][0]].push_back(++edges[i][1]);
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                toposort(i);
        reverse(topo.begin(), topo.end());
        for (int i = 0; i < n; i++)
            rev[topo[i]] = i + 1;
        for (int i = 0; i < (int)edges.size(); i++)
            if (rev[edges[i][0]] >= rev[edges[i][1]])
                return -1;
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++)
            ans = max(ans, calc(c));
        return ans;
    }
};