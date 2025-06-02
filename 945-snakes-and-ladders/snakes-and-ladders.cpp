class Solution {
public:
    int d[401],ne[401];
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=(int)board.size();
        int cn=0;
        for(int i=0;i<n;i++) 
        {
            if(i&1) for(int j=n-1;j>=0;j--)
            {
                cn++;
                if(board[n-i-1][j]+1) ne[cn]=board[n-i-1][j];
                else ne[cn]=cn;
            }
            else for(int j=0;j<n;j++)
            {
                cn++;
                if(board[n-i-1][j]+1) ne[cn]=board[n-i-1][j];
                else ne[cn]=cn;
            }
        }
        queue<int> q;
        d[1]=1;
        q.push(1);
        while((int)q.size())
        {
            int u=q.front();
            q.pop();
            for(int i=u+1;i<=min(n*n,u+6);i++)
            {
                int v=ne[i];
                if(!d[v])
                {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[n*n]-1;
    }
};