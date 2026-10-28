class Solution {
public:
vector<int>toposort(unordered_map<int,vector<int>>&adj,vector<int>&v)
{
    queue<int>q;
    vector<int>res;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        res.push_back(top);
        for(auto u:adj[top])
        {
           v[u]--;
           if(v[u]==0) q.push(u);
        }
    }
    return res.size()==adj.size()?res:vector<int>();
}
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<n; i++)
        {
            if(group[i] ==-1) group[i]=m++;
        }
        unordered_map<int,vector<int>>item;
        vector<int>itemin(n,0);
        unordered_map<int,vector<int>>groupitem;
        vector<int>groupin(m,0);
        for(int i=0; i<n; i++) item[i]=vector<int>();
        for(int i=0; i<m; i++) groupitem[i]=vector<int>();

            

        

        for(int i=0; i<n; i++)
        {
            for(auto u:beforeItems[i])
            {
                item[u].push_back(i);
                itemin[i]++;
                if(group[u]!=group[i]) 
                {
                    int prev=group[u];
                    int curr=group[i];
                    groupitem[prev].push_back(curr);
                    groupin[curr]++;
                }

            }
        }
        vector<int>itemorder=toposort(item, itemin);
        vector<int>grouporder=toposort(groupitem, groupin);
        vector<int>res;
        unordered_map<int,vector<int>>grouptoitem;
        for(auto v:itemorder)
        {
            int nitem=group[v];
            grouptoitem[nitem].push_back(v);
        }
       for(auto group:grouporder)
       {
         res.insert(res.end(),grouptoitem[group].begin(),grouptoitem[group].end());
       }
    return res;
    }
};