class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cn[26][26]={0};
        int ans=0;
        for(int i=0;i<(int)words.size();i++)
        {
            cn[words[i][0]-'a'][words[i][1]-'a']++;
        }
        bool ok=0;
        for(int i=0;i<26;i++) for(int j=i+1;j<26;j++)
        {
            int temp=min(cn[i][j],cn[j][i]);
            ans+=4*temp;
            cn[i][j]-=temp;cn[j][i]-=temp;
        }
        for(int i=0;i<26;i++)
        {
            int temp=cn[i][i]/2;
            ans+=4*temp;
            cn[i][i]-=2*temp;
            ok|=cn[i][i];    
        }
        return ans+ok*2;
    }
};