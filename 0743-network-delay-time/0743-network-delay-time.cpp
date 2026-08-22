class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int,vector<pair<int,int>>>mp;
       for(auto u:times)
       {
         int x=u[0];
         int y=u[1];
         int z=u[2];
         mp[x].push_back({y,z});
       } 

       vector<int>res(n+1,INT_MAX);

       priority_queue<pair<int,int>,
                      vector<pair<int,int>>,
                      greater<pair<int,int>>>pq;

       res[k]=0;
       pq.push({0,k});

       while(!pq.empty())
       {
           int dist=pq.top().first;
           int node=pq.top().second;
           pq.pop();

           for(auto u:mp[node])
           {
               int x=u.first;
               int d=u.second;

               if(dist+d<res[x])
               {
                   res[x]=dist+d;
                   pq.push({dist+d,x});
               }
           }
       }

   int mx=-1;
   for(int i=1; i<=n; i++)mx=max(mx,res[i]);
   return mx==INT_MAX?-1:mx;
   

    }
};