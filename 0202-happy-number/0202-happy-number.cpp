class Solution {
public:
int fun(int n)
{
  int sum=0;
  while(n)
  {
    int d=n%10;
    sum+=d*d;
    n/=10;
  }
  return sum;
}
    bool isHappy(int n) {
    int slow=n;
    int fast=n;
    while(fast!=1)
    {
        slow=fun(slow);
        fast=fun(fast);
        fast=fun(fast);
    if(slow==fast and slow!=1)return false;
    }
    return true;
    }
};