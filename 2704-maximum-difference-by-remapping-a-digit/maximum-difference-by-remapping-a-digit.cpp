class Solution {
public:
    int minMaxDifference(int num) {
        string n=to_string(num);
        string a=n,b=n;
        int j=0;
        while(n[j]=='9') j++;
        for(int i=(int)n.size()-1;i>=0;i--)
        {
            if(a[i]==a[0]) a[i]='0';
            if(b[i]==b[j]) b[i]='9';
        }
        return stoi(b)-stoi(a);
    }
};