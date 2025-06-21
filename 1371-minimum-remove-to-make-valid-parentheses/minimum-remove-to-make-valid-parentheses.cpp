class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t;
        int cn=0;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='(') 
            {
                cn++;
                t.push_back(s[i]);
            }
            else if(s[i]==')') 
            {
                cn--;
                if(cn>=0) t.push_back(s[i]);
                else cn++;
            }
            else t.push_back(s[i]);
        }
        string ans="";
        for(int i=(int)t.size()-1;i>=0;i--)
        {
            if(t[i]=='('&&cn>0) cn--;
            else ans.push_back(t[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};