class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&cmp)
{
    vis[i]=true;
    cmp.push_back(i);
    for(auto u:adj[i])
    {
        if(!vis[u])
        {
            vis[u]=true;
            dfs(u,adj,vis,cmp);
        }
    }

}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1);
        vector<bool>vis(n,false);
        for(auto &u:edges)
        {
            int i=u[0];
            int j=u[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int>cmp;
                dfs(i,adj,vis,cmp);
                bool c=true;
                for(auto u:cmp)
                {
                    if(adj[u].size()!=cmp.size()-1)
                    {
                        c=false;
                        break;
                    }
                }
                if(c)cnt++;
            }
        }
        return cnt;
    }
};