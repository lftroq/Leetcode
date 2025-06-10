class Solution {
public:
    int maxDifference(string s) {
        int cn[26]={0};
        for(int i=0;i<(int)s.size();i++) cn[s[i]-'a']++;
        int mxo=0,mne=101;
        for(int i=0;i<26;i++)
        {
            if(cn[i]&1) mxo=max(mxo,cn[i]);
            else if(cn[i]) mne=min(mne,cn[i]);
        }
        return mxo-mne;
    }
};