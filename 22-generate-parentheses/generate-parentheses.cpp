class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int mask=0;mask<(1<<(2*n));mask++)
        {
            int ok=1,cn=0;
            for(int i=0;i<2*n;i++) 
            {
                if(mask>>i&1) cn++; else cn--;
                ok&=(cn>=0);
            }
            ok&=(cn==0);
            if(ok) 
            {
                string temp="";
                for(int i=0;i<2*n;i++) if(mask>>i&1) temp.push_back('('); else temp.push_back(')');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};