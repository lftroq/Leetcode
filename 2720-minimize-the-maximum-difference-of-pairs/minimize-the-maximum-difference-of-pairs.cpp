class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=(int)nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0],ans=r;
        while(l<=r)
        {
            int mid=(l+r)>>1,cn=0;
            for(int i=1;i<n;i++) if(mid>=nums[i]-nums[i-1]) 
            {
                cn++;
                i++;
            }
            if(cn>=p) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};