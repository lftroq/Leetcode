class Solution {
public:
#define fi first
#define se second
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = (int)moveTime.size(), m = (int)moveTime[0].size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(m, -1)));
        priority_queue<pair<pair<int, int>, pair<int, int>>,
                       vector<pair<pair<int, int>, pair<int, int>>>,
                       greater<pair<pair<int, int>, pair<int, int>>>>
            pq;
        pq.push({{dp[0][0][0] = 0, 0}, {0, 0}});
        while ((int)pq.size()) {
            int temp = pq.top().fi.fi, t = pq.top().fi.se, x = pq.top().se.fi,
                y = pq.top().se.se;
            pq.pop();
            if (dp[t][x][y] != temp)
                continue;
            if(x == n - 1 && y == m - 1) return temp;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m)
                    continue;
                if (dp[t ^ 1][xx][yy] == -1 ||
                    dp[t ^ 1][xx][yy] > max(moveTime[xx][yy], dp[t][x][y]) + 1 + t)
                    pq.push({{dp[t ^ 1][xx][yy] =
                                  max(moveTime[xx][yy], dp[t][x][y]) + 1 + t,
                              t ^ 1},
                             {xx, yy}});
            }
        }
        return -1;
    }
};