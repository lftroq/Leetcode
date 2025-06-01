class Solution {
public:
    bool isValid(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')') 
            {
                if(ans.size()&&ans.back()=='(') ans.pop_back();
                else return false;
            }
            else if(s[i]==']') 
            {
                if(ans.size()&&ans.back()=='[') ans.pop_back();
                else return false;
            }
            else if(s[i]=='}') 
            {
                if(ans.size()&&ans.back()=='{') ans.pop_back();
                else return false;
            }
            else ans.push_back(s[i]);
        }
        return ans=="";
    }
};