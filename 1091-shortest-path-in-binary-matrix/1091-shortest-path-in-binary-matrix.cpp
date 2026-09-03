class Solution {
public:
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
bool valid(int i, int j, int n, int  m)
{
    return i>=0 and i<n and j>=0 and j<m;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       if(grid[0][0]==1 or grid[n-1][m-1]==1) return -1;
       int move=0;
       queue<pair<int,int>>q;
       q.push({0,0});
       grid[0][0]=1;
     while(!q.empty())
     {
        int sz=q.size();
        while(sz--)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
        if(row==n-1 and col==m-1) return ++move;
        for(int k=0; k<8; k++)
        {
          int i=row+dx[k];
          int j=col+dy[k];
        
        if(valid(i, j, n, m) and grid[i][j]!=1)
        {
            q.push({i,j});
            grid[i][j]=1;
        }
        }
        }
        move++;
     }
     return -1;
    }
};