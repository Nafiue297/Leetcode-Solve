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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
    auto lamda=[&](vector<int>&a,vector<int>&b)
    {
        return a[2]<b[2];
    };
    sort(edgeList.begin(),edgeList.end(),lamda);
    sort(queries.begin(),queries.end(),lamda);
    int j=0;
    vector<bool>res(queries.size());
    for(int i=0;i<queries.size();i++)
    {
        vector<int>ind=queries[i];
        int u=ind[0];
        int v=ind[1];
        int x=ind[2];
        int y=ind[3];
    while(j<edgeList.size() and edgeList[j][2]<x)
    {
        dsu.Union(edgeList[j][0],edgeList[j][1]);
        j++;
    }
    if(dsu.Find(u)!=dsu.Find(v))
    res[y]=false;
    else res[y]=true;
    }
    return res;
    }
};