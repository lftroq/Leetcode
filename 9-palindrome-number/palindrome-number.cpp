class Solution {
public:
    bool isPalindrome(int x) {
        string s="";
        if(x<0) s+='-';
        while(x)
        {
            s=(char)((x%10)+'0')+s;
            x/=10;
        }
        for(int i=0;i<s.size();i++) if(s[i]!=s[s.size()-i-1]) return false;
        return true;
    }
};