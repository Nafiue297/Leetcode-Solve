class Solution {
public:
 int dx[4]={0,1,0,-1};
 int dy[4]={-1,0,1,0};
 int n,m;
 bool valid(int r, int c)
 {
    return r>=0 and r<n and c>=0 and c<m;
 }
 void bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>& grid, vector<int>& pricing,  vector<vector<int>>&store)
 {
    vector<vector<int>>vis(n,vector<int>(m,-1));
    while(!q.empty())
    {
        pair<pair<int,int>,int>p;
        p=q.front();
        q.pop();
        int row=p.first.first;
        int col=p.first.second;
        int dist=p.second;
        vis[row][col]=1;
        if(grid[row][col]>=pricing[0] and grid[row][col]<=pricing[1])
      {
        vector<int>res;
        res.push_back(dist);
        res.push_back(grid[row][col]);
        res.push_back(row);
        res.push_back(col);
        store.push_back(res);
      }
      for(int k=0; k<4; k++)
      {
        int nrow=row+dx[k];
        int ncol=col+dy[k];
    if(valid(nrow,ncol) and grid[nrow][ncol]!=0 and vis[nrow][ncol]!=1 )
    {
        q.push({{nrow,ncol},dist+1});
        vis[nrow][ncol]=1;
    } 
    
      }  
    }
 }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{start[0],start[1]},0});
        vector<vector<int>>store;
        bfs(q,grid,pricing,store);
        sort(begin(store), end(store));
        int r=store.size()<=k?store.size():k;
        vector<vector<int>>ans(r);
        for(int i=0; i<r; i++)
        {
          ans[i].push_back(store[i][2]);
          ans[i].push_back(store[i][3]);
         }
       return ans;
    }
};