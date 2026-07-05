class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
bool helper(vector<vector<int>>&dist,int mid,int r)
{ 
    if(dist[0][0]<mid)return false;
    vector<vector<bool>>vis(r,vector<bool>(r,false));
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=true;

    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i==r-1 and j==r-1)return true;
        for(int k=0;k<4;k++)
        {
            int row=i+dx[k];
            int col=j+dy[k];
            if(valid(row,col,r,r) and vis[row][col]!=true and dist[row][col]>=mid)
            {
                q.push({row,col});
                vis[row][col]=true;
            }
        }
    }
    return false;
}
bool valid(int row,int col,int n,int m)
{
    if(row>=0 and col>=0 and row<n and col<m)return true;
    return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dist(r,vector<int>(c,-1));
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                dist[i][j]=level;
                for(int k=0;k<4;k++)
                {
                    int row=i+dx[k];
                    int col=j+dy[k];
                    if(valid(row,col,r,c) and vis[row][col]!=true)
                    {
                        q.push({row,col});
                        vis[row][col]=true;
                    }
                }
            }
            level++;
        }
        int low=1;
        int high=INT_MAX;
        int ans=0;
        while(low<=high)
        {
           int mid=low+(high-low)/2;
           if(helper(dist,mid,r))
           {
            ans=mid;
            low=mid+1;
           }else high=mid-1;
        }
          return ans;
    }
};