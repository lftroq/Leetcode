class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++) ans.push_back(to_string(i));
        sort(ans.begin(),ans.end());
        vector<int> ans1;
        for(int i=0;i<n;i++) ans1.push_back(stoi(ans[i]));
        return ans1; 
    }
};