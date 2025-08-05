class Solution {
public:
    int totalFruit(vector<int>& a) {
        int ans=0;
        map<int,int> mp;
        for(int i=0,j=0;i<(int)a.size();i++)
        {
            mp[a[i]]++;
            while(mp.size()>2)
            {
                mp[a[j]]--;
                if(!mp[a[j]]) mp.erase(a[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};