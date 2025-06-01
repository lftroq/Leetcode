class Solution {
public:
    vector<string> ans;
    string cur="";
    map<char,string> mp;
    void waylouis(string &s,int i)
    {
        if(i==(int)s.size())
        {
            ans.push_back(cur);
            return;
        }
        for(char x:mp[s[i]])
        {
            cur.push_back(x);
            waylouis(s,i+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        waylouis(digits,0);
        return ans;
    }
};