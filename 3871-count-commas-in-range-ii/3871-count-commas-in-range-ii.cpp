class Solution {
public:
using ll = long long;
    long long countCommas(long long n) {
       int cnt=1;
       ll res=0;
       ll lower=1000;
       while(lower<=n)
       {
       ll upper=min(n,lower*1000ll-1);
       ll num=(upper-lower)+1;
        res+=num*cnt;
        lower*=1000;
        cnt++;

       } 
       return res;
    }
};