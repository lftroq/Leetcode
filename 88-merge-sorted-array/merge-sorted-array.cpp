class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for(int i = 0, j = 0; i < m || j < n;)
        {
            if(i == m) temp.push_back(nums2[j++]);
            else if(j == n || nums1[i] < nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }
        swap(nums1, temp);
    }
};