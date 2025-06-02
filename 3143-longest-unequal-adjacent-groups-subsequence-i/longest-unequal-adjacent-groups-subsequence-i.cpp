class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int prev=-1;
        for(int i=0;i<(int)groups.size();i++)
        {
            if(groups[i]!=prev)
            {
                prev=groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};