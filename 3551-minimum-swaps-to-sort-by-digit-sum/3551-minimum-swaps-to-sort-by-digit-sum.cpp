class Solution {
public:
int digit(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
      int n=nums.size();
      vector<int>v=nums;
      auto lamda=[&](int num1, int num2)
      {
          int n1=digit(num1);
          int n2=digit(num2);
          if(n1!=n2) return n1<n2;
          return num1<num2;
      };
      sort(begin(v),end(v),lamda);  
      unordered_map<int,int>mp;
      for(int i=0; i<n; i++) mp[nums[i]]=i;
      int cnt=0;
      for(int i=0; i<n; i++)
      {
        int expect=v[i];
        int orginal=nums[i];
        if(expect == orginal) continue;
        int idx=mp[expect];
        nums[i]=expect;
        nums[idx]=orginal;
        mp[expect]=i;
        mp[orginal]=idx;
        cnt++;


      }
    return cnt;

      
    }
};