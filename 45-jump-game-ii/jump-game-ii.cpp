class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0, ans = 0, ma = 0;
        for(int i = 0; i + 1 < (int)nums.size(); i++)
        {
            ma = max(ma, i + nums[i]);
            if(i == cur)
            {
                ans++;
                cur = ma;
            }
        }
        return ans;
    }
};