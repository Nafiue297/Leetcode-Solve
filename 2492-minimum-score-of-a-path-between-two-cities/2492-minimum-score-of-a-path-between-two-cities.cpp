class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<bool>vis(n,false);
        for(auto &u:roads)
        {
            int a1=u[0];
            int b2=u[1];
            int dist=u[2];
            adj[a1].push_back({b2,dist});
            adj[b2].push_back({a1,dist});
        }
        queue<int>q;
        q.push(1);
        vis[1]=true;
        int ans=INT_MAX;
        while(!q.empty())
        {
           int u=q.front();
           q.pop();
           for(auto [i,j]:adj[u])
           
           {

            
              ans=min(ans,j);
           
         
           if(!vis[i])
           {
            q.push(i);
            vis[i]=true;
           }
           
        }
        }
        return ans;
    }
};