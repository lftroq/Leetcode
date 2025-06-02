class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cn=1;
        int cur=nums[0];
        for(int i=1;i<(int)nums.size();i++)
        {
            if(cn<=0)
            {
                cn=1;
                cur=nums[i];
            }
            else if(nums[i]==cur) cn++;
            else cn--;
        }
        return cur;
    }
};