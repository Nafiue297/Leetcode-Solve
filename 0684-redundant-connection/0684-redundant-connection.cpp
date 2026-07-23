class DSU{
public:
vector<int>parent,rank;
DSU(int n)
{
    parent.resize(n+1);
    rank.resize(n+1,0);
    for(int i=1;i<=n;i++)parent[i]=i;

}
int Find(int x)
{
    if(parent[x]==x)return x;
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
    }else{
        parent[px]=py;
        rank[py]++;
    }
}
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n=edges.size();
      DSU dsu(n);
      for(auto u:edges)
      {
       
        if(dsu.Find(u[0])==dsu.Find(u[1]))return u;
        dsu.Union(u[0],u[1]);
      }
     return {};
    }
};