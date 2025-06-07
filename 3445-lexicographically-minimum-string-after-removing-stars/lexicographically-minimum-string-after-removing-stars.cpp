class Solution {
public:
    string clearStars(string s) {
        vector<int> v[26],liem(s.size(),0);
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='*')
            {
                for(int j=0;j<26;j++) if(v[j].size())
                {
                    liem[v[j].back()]=1;
                    v[j].pop_back();
                    break;
                }
                liem[i]=1;
            }
            else v[s[i]-'a'].push_back(i);
        }
        string ans="";
        for(int i=0;i<(int)s.size();i++) if(!liem[i]) ans.push_back(s[i]);
        return ans;
    }
};