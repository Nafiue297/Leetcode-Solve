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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                
              if(mp.find(mail)==mp.end())
              {
                mp[mail]=i;
              }else
              {
                dsu.Union(i,mp[mail]);
              }
            }
        }
        vector<string>s[n];
       for(auto u:mp)
       {
         string s1=u.first;
         int no=dsu.Find(u.second);
         s[no].push_back(s1);
       }
    vector<vector<string>>res;
    for(int i=0;i<n;i++)
    {
        if(s[i].size()==0)continue;
        sort(s[i].begin(),s[i].end());
       vector<string>tmp;
       tmp.push_back(accounts[i][0]);
       for(auto u:s[i])
       {
        tmp.push_back(u);

       }
       res.push_back(tmp);
        
    }   
      return res;
    }
};