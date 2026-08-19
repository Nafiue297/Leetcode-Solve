class Solution {
public:

 int solve(vector<int>&piles, int person, int i, int m, int n, int t[2][101][101])
 {
    if(i>=n) return 0;
    if(t[person][i][m]!=-1) return t[person][i][m];
    int stone=0;
    int result=(person==1)?-1:INT_MAX;
   for(int x=1; x<=min(2*m,n-i); x++)
   {
   stone+=piles[i+x-1];
   if(person==1)
   {
    result=max(result,stone+solve(piles, 0, i+x, max(m,x), n, t));
   }else result=min(result,solve(piles, 1, i+x, max(m,x), n, t));

   }
   return t[person][i][m]=result;
 }
    int stoneGameII(vector<int>& piles) {
    int n=piles.size();
    int t[2][101][101];
    int m=1;
    memset(t,-1,sizeof(t));
    return solve(piles, 1, 0, m, n, t); 
    }
};