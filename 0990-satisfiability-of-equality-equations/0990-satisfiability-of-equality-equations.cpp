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
    else if(rank[parent_x]>rank[parent_y])
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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<parent.size();i++)parent[i]=i;
        for(auto u:equations)
        {
            if(u[1]=='=')
            {
                Union(u[0]-'a',u[3]-'a');
            }
        }
        for(auto u:equations)
        {
            if(u[1]=='!')
            {
                int parent_first=Find(u[0]-'a');
                int parent_second=Find(u[3]-'a');
                if(parent_first==parent_second)return false;
            }
        }
        return true;
    }
};