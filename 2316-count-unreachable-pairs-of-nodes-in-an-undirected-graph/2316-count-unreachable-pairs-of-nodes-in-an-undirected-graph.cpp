class Solution {
public:
vector<int>parent;
vector<int>rank;
int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}
void Union(int x,int y)
{
    int parent_x=Find(x);
    int parent_y=Find(y);
    if(parent_x==parent_y)return;
    if(rank[parent_x]>rank[parent_y])
    {
        parent[parent_y]=parent_x;
    }else if(rank[parent_x]<rank[parent_y])
    {
        parent[parent_x]=parent_y;
    }
    else
    {
        parent[parent_x]=parent_y;
        rank[parent_y]++;
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<parent.size();i++)parent[i]=i;
        unordered_map<int,int>mp;
        for(auto u:edges)
        {
            Union(u[0],u[1]);
        }
        for(int i=0;i<n;i++)
        {
            int papa=Find(i);
            mp[papa]++;
        }
        long long res=0;
        long long cmp=n;
        for(auto u:mp)
        {
            int sz=u.second;
            res+=(sz)*(cmp-sz);
            cmp-=sz;
        }
        return res;
    }
};