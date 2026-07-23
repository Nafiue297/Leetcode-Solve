class DSU{
public:
vector<int>parent,rank;
DSU(int n)
{
    parent.resize(n);
    rank.resize(n,0);
    for(int i=0;i<n;i++)parent[i]=i;
}
int Find(int x)
{
    if(x==parent[x])return x;
    return parent[x]=Find(parent[x]);
}
void Union(int x,int y)
{
    int px=Find(x);
    int py=Find(y);
    if(px==py)return;
    if(rank[px]>rank[py])
    {
        parent[py]=px;

    }else if(rank[px]<rank[py])
    {
        parent[px]=py;
    }else
    {
        parent[px]=py;
        rank[py]++;
    }
}
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto u:edges)
        {
           dsu.Union(u[0],u[1]);
        }
        if(dsu.Find(source)!=dsu.Find(destination))return false;
        return true;
    }
};