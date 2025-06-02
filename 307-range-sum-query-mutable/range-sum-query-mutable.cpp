class NumArray {
public:
    int n;
    vector<int> bit, a;
    NumArray(vector<int>& nums) {
        n = (int)nums.size();
        bit.resize(n + 1, 0);
        a.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            up(i + 1, nums[i]);
            a[i + 1] = nums[i];
        }
    }

    void up(int idx, int val) {
        for (; idx <= n; idx += (idx & (-idx)))
            bit[idx] += val;
    }

    void update(int index, int val) {
        index++;
        up(index, -a[index]);
        a[index] = val;
        up(index, a[index]);
    }

    int sumRange(int left, int right) {
        int ans = 0;
        right++;
        for (; right; right -= (right & (-right)))
            ans += bit[right];
        for (; left; left -= (left & (-left)))
            ans -= bit[left];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */