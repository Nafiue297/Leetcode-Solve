class Solution {
public:
vector<int>parent;
vector<int>rank;
int Find(int x)
{
    if(parent[x]==x)return x;
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

    }
    else if(rank[parent_x]<rank[parent_y])
    {
        parent[parent_x]=parent_y;
    }else
    {
        parent[parent_x]=parent_y;
        rank[parent_y]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        int con=n;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto u:connections)
        {
            if(Find(u[0])!=Find(u[1]))
            {
                Union(u[0],u[1]);
                con--;
            }
        }
        return --con;
    }
};