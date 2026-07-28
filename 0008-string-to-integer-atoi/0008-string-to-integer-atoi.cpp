class Solution {
public:
int ans(string& s,int i,long long res,int sign)
{
    if(i>=s.size() or !isdigit(s[i]))
    return res*sign;
    res=res*10+(s[i]-'0');
    if(res*sign>=INT_MAX)return INT_MAX;
    if(res*sign<=INT_MIN)return INT_MIN;
   return ans(s,i+1,res,sign);
}
    int myAtoi(string s) {
      int n=s.size();
      int i=0,sign=1;
      while(i<n and s[i]==' ')i++;
     if(s[i]=='+' or s[i]=='-')
     {
        sign=(s[i]=='-')?-1:1;
        i++;
     }
     while(i<n and s[i]=='0')i++;
     return ans(s,i,0l,sign);
    }
};