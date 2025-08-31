class Solution {
public:
    bool ok=false;
    int a[9][9];
    int row[9],col[9],box[3][3];
    
    void waylouis(int x,int y)
    {
        if(ok) return;
        if(x==9)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++) cout << a[i][j] << ' ';
                cout << endl;
            }
            ok=1;
            return;
        }
        int nx=x,ny=y+1;
        if(ny==9) ny-=9,nx++;
        if(a[x][y]) waylouis(nx,ny);
        else for(int j=1;j<=9;j++)
        {
            if(row[x]>>j&1) continue;
            if(col[y]>>j&1) continue;
            if(box[x/3][y/3]>>j&1) continue;
    
            a[x][y]=j;
            row[x]|=(1<<j);
            col[y]|=(1<<j);
            box[x/3][y/3]|=(1<<j);
    
            waylouis(nx,ny);
            if(ok) break;
    
            a[x][y]=0;
            row[x]^=(1<<j);
            col[y]^=(1<<j);
            box[x/3][y/3]^=(1<<j);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) 
        {
            char c=board[i][j];
            if(c=='.') a[i][j]=0;
            else a[i][j]=(c-'0');
            if(a[i][j])
            {
                row[i]|=(1<<a[i][j]);
                col[j]|=(1<<a[i][j]);
                box[i/3][j/3]|=(1<<a[i][j]);
            }
        }
        waylouis(0,0);
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) board[i][j]=a[i][j]+'0';
    }
};