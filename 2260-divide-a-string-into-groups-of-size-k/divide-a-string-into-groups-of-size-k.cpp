class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0;i<(int)s.size();i+=k)
        {
            if(i+k-1<(int)s.size()) ans.push_back(s.substr(i,k));
            else
            {
                string temp=s.substr(i,k);
                while(temp.size()<k) temp.push_back(fill);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};