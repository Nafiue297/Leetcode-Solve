class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        int step=0;
        for(auto u:flights)
        {
            int x=u[0];
            int y=u[1];
            int z=u[2];
        adj[x].push_back({y,z});
        }
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    queue<pair<int,int>>q;
    q.push({src,0});
    while(!q.empty() and step<=k)
    {
        int sz=q.size();
        while(sz--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
        for(auto u:adj[x])
        {
            int ds=u.first;
            int dy=u.second;
        if(dist[ds]>dy+y)
        {
            dist[ds]=dy+y;
            q.push({ds,dy+y});
        }
        }

        }
        step++;
    }
    return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};