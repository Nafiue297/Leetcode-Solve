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
    }else{
        parent[px]=py;
        rank[py]++;
    }
}
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU dsu(n);
        for(auto u:pairs)
        {
            dsu.Union(u[0],u[1]);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int first=dsu.Find(i);
            mp[first].push_back(i);
        }
        for(auto u:mp)
        {
            vector<int>ind=u.second;
            vector<char>c;
            for(auto u:ind)
            {
                c.push_back(s[u]);
            }
            sort(ind.begin(),ind.end());
            sort(c.begin(),c.end());
        for(int j=0;j<ind.size();j++)
        {
            s[ind[j]]=c[j];
        }
        }
        return s;
    }
};