class Solution {
public:
    bool check(string &s,string &t,int k)
    {
        // s in t
        int c=0,j=0,cn=0;
        for(int i=0;i<(int)t.size();i++)
        {
            char cc=t[i];
            if(cc==s[j])
            {
                j++;
                if(j==(int)s.size())
                {
                    j=0;
                    cn++;
                }
            }
        }
        return cn>=k;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        queue<string> q;
        q.push("");
        while(q.size())
        {
            string u=q.front();
            q.pop();
            for(char c='a';c<='z';c++)
            {
                string v=u;
                v.push_back(c);
                if(check(v,s,k))
                {
                    ans=v;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};