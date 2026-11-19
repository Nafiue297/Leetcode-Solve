class Solution {
public:
int mxbad(vector<int>v)
{
       sort(begin(v),end(v));
       v.pop_back();
       v.pop_back();
       int mx=*max_element(begin(v),end(v));
       int mn=*min_element(begin(v),end(v));
       return mx-mn; 
}
int mnbad(vector<int>v)
{
    sort(rbegin(v),rend(v));
    v.pop_back();
    v.pop_back();
    int mx=*max_element(begin(v),end(v));
    int mn=*min_element(begin(v),end(v));
    return mx-mn;
}
int mxmn(vector<int>v)
{
    sort(rbegin(v),rend(v));
    v.pop_back();
    reverse(begin(v),end(v));
    v.pop_back();
    int mx=*max_element(begin(v),end(v));
    int mn=*min_element(begin(v),end(v));
    return mx-mn;

}
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return 0;
       vector<int>v=nums;
       return min({mxbad(v),mnbad(v),mxmn(v)});
    }
};