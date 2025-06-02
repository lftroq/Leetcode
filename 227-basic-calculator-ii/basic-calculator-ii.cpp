class Solution {
public:
    int calculate(string s) {
        string temp="";
        for(int i=0;i<s.size();i++) if((s[i]>='0'&&s[i]<='9')||(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')) temp.push_back(s[i]);
        s=temp;
        vector<int> num;
        vector<char> op;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                if(i==0||(i!=0&&!(s[i-1]>='0'&&s[i-1]<='9')))
                {
                    num.push_back(s[i]-'0');
                    continue;
                }
                num.back()*=10;num.back()+=s[i]-'0';
            }
            else op.push_back(s[i]);
        }
        for(int i=0;i<op.size();i++) if(op[i]=='*'||op[i]=='/')
        {
            if(op[i]=='*') num[i+1]*=num[i];
            else
            {
                num[i+1]=num[i]/num[i+1];
            }
            num[i]=0;
            op[i]=(i==0?'+':op[i-1]);
        }
        int ans=num[0];
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=='+') ans+=num[i+1];
            else ans-=num[i+1];
        }
        return ans;
    }
};