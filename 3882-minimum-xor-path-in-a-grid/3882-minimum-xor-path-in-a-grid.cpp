class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<tuple<int,int,int>>q;
    vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(1024,false)));
       q.push({0,0,grid[0][0]});
       vis[0][0][grid[0][0]]=true;
     
       while(!q.empty())
       {
         auto [i,j,xr]=q.front();
         q.pop();
        
         if(i+1 < n)
         {
            int nx=xr^grid[i+1][j];
            if(!vis[i+1][j][nx]){
                 q.push({i+1, j, nx});
                 vis[i+1][j][nx]=true;
            }
           
         } 
         if(j+1 < m) {
            int nx=xr^grid[i][j+1];
            if(!vis[i][j+1][nx]){
                q.push({i, j+1, nx});
                vis[i][j+1][nx]=true;
            }
            
       } 
     
       } 
        for(int i=0; i<1024; i++)  if(vis[n-1][m-1][i]) return i;
        return 0;
    }
};