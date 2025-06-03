class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=(int)nums.size();
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {
            map<long long,bool> mp;
            for(int j=0;j<i;j++) mp[nums[i]+nums[j]]=true;
            for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) 
            {
                if(mp[1ll*target-nums[j]-nums[k]]) 
                {
                    ans.push_back({target-nums[i]-nums[j]-nums[k],nums[i],nums[j],nums[k]});
                    sort(ans.back().begin(),ans.back().end());
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};