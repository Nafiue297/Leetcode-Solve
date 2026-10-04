class Solution {
public:
bool dfs(vector<vector<int>>&adj, int i, vector<bool>&vis, vector<bool>&ind)
{
    vis[i]=true;
    ind[i]=true;
    for(auto u:adj[i])
    {
        if(!vis[u] and dfs(adj, u, vis, ind)) return true;
        else if(ind[u]==true) return true;
    }
    ind[i]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++)
        {
            for(auto u:graph[i])adj[i].push_back(u);
        }
        vector<bool>vis(n,false);
        vector<bool>ind(n,false);
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs(adj, i, vis, ind);
        }
        vector<int>res;
        for(int i=0; i<n; i++)
        {
            if(!ind[i]) res.push_back(i);
        }
        return res;
    }
};