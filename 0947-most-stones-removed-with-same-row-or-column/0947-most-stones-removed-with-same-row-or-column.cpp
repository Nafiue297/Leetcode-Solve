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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU dsu(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])
                {
                    dsu.Union(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<dsu.parent.size();i++)
        {
            if(dsu.parent[i]==i)cnt++;
        }
        return n-cnt;
    }
};