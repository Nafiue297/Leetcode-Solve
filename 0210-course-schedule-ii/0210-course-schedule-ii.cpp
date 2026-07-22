class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 
        int n=numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int> cnt;
        for(auto u:prerequisites)
        {
            int i=u[0];
            int j=u[1];
            adj[j].push_back(i);
            indegree[i]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                cnt.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto i:adj[u])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                    cnt.push_back(i);
                }
            }
        }
        if(cnt.size()==0 or cnt.size()!=n)return {};
        return cnt;
    }
};
