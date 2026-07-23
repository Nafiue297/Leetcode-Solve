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
    if(parent[x]==x)return x;
    return parent[x]=Find(parent[x]);
 }
 void Union(int x,int y)
 {
    int px=Find(x);
    int py=Find(y);
    if(px==py)return;
    else if(rank[px]>rank[py])
    {
        parent[py]=px;

    }
    else if(rank[px]<rank[py])
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
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
      int provinces=n;
      DSU dsu(n);
     for(int i=0;i<n;i++) 
     {
        for(int j=i+1;j<n;j++)
        {
            if(isConnected[i][j]==1)
            {
                if(dsu.Find(i)!=dsu.Find(j))
                {
                    dsu.Union(i,j);
                    provinces--;
                }
            }
        }
     }
     return provinces;
    }
};