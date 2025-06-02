class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool cn[101] = {0};
        int ans = ((int)nums.size() + 2) / 3;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            if (cn[nums[i]])
                break;
            cn[nums[i]] = true;
            if (i % 3 == 0)
                ans = i / 3;
        }
        return ans;
    }
};