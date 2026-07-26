class DSU{
public:
vector<int>parent,rank;
DSU(int n)
{
    parent.resize(n+1);
    rank.resize(n+1,0);
    for(int i=1;i<n+1;i++)parent[i]=i;
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
    if(rank[px]>rank[py])parent[py]=px;
    else if(rank[px]<rank[py])parent[px]=py;
    else {
        parent[px]=py;
        rank[py]++;
    }
}
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n+1);
        DSU bob(n+1);
    sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
          return a[0]>b[0];
    });
    int edge=0,ac=0,bc=0;
    for(auto u:edges)
    {
        if(u[0]==3)
        {
            if(alice.Find(u[1])!=alice.Find(u[2]))
            {
                alice.Union(u[1],u[2]);
                ac++;
                
            }
            if(bob.Find(u[1])!=bob.Find(u[2]))
            {
                bob.Union(u[1],u[2]);
                bc++;
            }
            else edge++;
        }
      
    else if(u[0]==1)
    {
        if(alice.Find(u[1])!=alice.Find(u[2]))
        {
            alice.Union(u[1],u[2]);
            ac++;
        }else edge++;
    }
    else if(u[0]==2)
    {
        if(bob.Find(u[1])!=bob.Find(u[2]))
        {
            bob.Union(u[1],u[2]);
            bc++;
        }else edge++;
    }
        
    }
    return (ac==n-1 and bc==n-1)?edge:-1;
    }
};