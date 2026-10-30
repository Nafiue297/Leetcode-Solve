class Solution {
public:
typedef tuple<int,int,int>T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto u: edges)
        {
            int i=u[0];
            int j=u[1];
            int K=u[2];
            adj[i].push_back({j,K});
        }
        vector<vector<int>>res(n,vector<int>(k+1,INT_MAX));
        priority_queue<T,vector<T>,greater<T>>pq;
        res[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty())
        {
          auto [u,node,cnt]=pq.top();
          pq.pop();
          if(u>res[node][cnt]) continue;
          if(node==n-1) return u;
          for(auto v: adj[node])
          {
            int adjnode=v[0];
            int wt     =v[1];
            int ncnt=(labels[adjnode] == labels[node])?cnt+1:1;
            if(ncnt>k) continue;
            int ndist=u+wt;
            if(ndist<res[adjnode][ncnt])
            {
                res[adjnode][ncnt]=ndist;
                pq.push({ndist,adjnode,ncnt});
            }
          }

        }
      return -1;
    }
};