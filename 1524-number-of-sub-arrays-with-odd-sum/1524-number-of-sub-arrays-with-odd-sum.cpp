class Solution {
public:
const int m=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
      int n=arr.size();
      int cnt=0;
      int sum=0;
      int even=1,odd=0;
      for(int i=0; i<n; i++)
      {
        sum+=arr[i];
        if(sum%2==0)
        {
            cnt=(cnt+odd)%m;
            even++;
        }else
        {
            cnt=(cnt+even)%m;
            odd++;
        }

      } 
      return cnt; 
    }
};