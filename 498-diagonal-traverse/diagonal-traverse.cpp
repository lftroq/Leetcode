class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        pair<int, int> pos;
        pos = {0, 0};
        int n = (int)mat.size(), m = (int)mat[0].size();
        vector<int> ans;
        bool c = 0;
        while((int)ans.size() < n * m) {
            int x = pos.first, y = pos.second;
            pos.first++;
            if(pos.first == n) pos.first--, pos.second++; 
            vector<int> v;
            while(x >= 0 && y < m) {
                v.push_back(mat[x][y]);
                x--;y++;
            }
            if(c&1) reverse(v.begin(), v.end());
            for(int i = 0; i < (int)v.size(); i++) ans.push_back(v[i]);
            c^=1;
        }
        return ans;
    }
};