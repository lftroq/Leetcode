class Solution {
public:
    bool doesAliceWin(string s) {
        for(int i=0;i<(int)s.size();i++) if(s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='e'||s[i]=='u') return true;
        return false;
    }
};