class Solution {
public:
bool topo(int n,unordered_map<int,vector<int>>&mp,vector<int>&indegree)
{
    queue<int>q;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
           q.push(i);
           cnt++;
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:mp[u])
        {
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
                cnt++;
            }
        }
    }
    return n==cnt;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(n,0);
       
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            indegree[u]++;
            mp[v].push_back(u);
        }
     return topo(n,mp,indegree);
    }
};