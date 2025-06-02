class Solution {
public:
#define fi first
#define se second
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = (int)moveTime.size(), m = (int)moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({dp[0][0] = 0, {0, 0}});
        while ((int)pq.size()) {
            int temp = pq.top().fi, x = pq.top().se.fi, y = pq.top().se.se;
            pq.pop();
            if (dp[x][y] != temp)
                continue;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m)
                    continue;
                if (dp[xx][yy] == -1 ||
                    dp[xx][yy] > max(moveTime[xx][yy], dp[x][y]) + 1)
                    pq.push({dp[xx][yy] = max(moveTime[xx][yy], dp[x][y]) + 1,
                             {xx, yy}});
            }
        }
        return dp[n - 1][m - 1];
    }
};