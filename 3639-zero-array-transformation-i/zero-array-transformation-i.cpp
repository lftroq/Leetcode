class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>prefixsum(n,0);
        for(vector<int>&vtr:queries){
            prefixsum[vtr[0]]--;
            if (vtr[1]+1<n) prefixsum[vtr[1]+1]++;
        }
        for(int i=1;i<n;i++){
            prefixsum[i]+=prefixsum[i-1];
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" "<<prefixsum[i]<<'\n';
            if (nums[i]+prefixsum[i]>0) return 0; 
        }
        return 1;
    }
};