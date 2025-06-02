class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> p;
        p.push_back(nums[0]);
        for (int i = 1; i < (int)nums.size(); i++)
            p.push_back(p.back() + nums[i]);
        long long ans = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int l = 0, r = i, j = i + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if ((p[i] - (mid - 1 >= 0 ? p[mid - 1] : 0)) * (i - mid + 1) < k) {
                    j = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};