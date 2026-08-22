class Solution {
public:
int sum(int n)
{
    int add=0;
    while(n>0)
    {
        add+=n%10;
        n/=10;
    }
    return add;
}
int mul(int n)
{
    int add=1;
    while(n>0)
    {
        add*=n%10;
        n/=10;
    }
    return add;
}
    bool checkDivisibility(int n) {
      int res=sum(n)+mul(n);
      return n%res==0;
    }
};