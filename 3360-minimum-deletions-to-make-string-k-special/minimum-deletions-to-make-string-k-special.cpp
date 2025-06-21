class Solution {
public:
    int minimumDeletions(string word, int k) {
        int cn[26]={0};
        for(int i=0;i<(int)word.size();i++) cn[word[i]-'a']++;
        int ans=(int)word.size();
        for(int i=0;i<26;i++) if(cn[i]!=0)
        {
            int temp=0;
            for(int j=0;j<26;j++) if(cn[j]!=0)
            {
                if(cn[j]<cn[i]) temp+=cn[j];
                else if(cn[j]>cn[i]+k) temp+=cn[j]-cn[i]-k;
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};