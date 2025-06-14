class Solution {
public:
    int minMaxDifference(int num) {
        string a=to_string(num);
        string b=a;
        int j=0;
        while(b[j]=='9') j++;
        for(int i=(int)b.size()-1;i>=0;i--)
        {
            if(a[i]==a[0]) a[i]='0';
            if(b[i]==b[j]) b[i]='9';
        }
        return stoi(b)-stoi(a);
    }
};