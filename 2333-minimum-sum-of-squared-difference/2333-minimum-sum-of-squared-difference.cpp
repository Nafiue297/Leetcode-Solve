class Solution {
public:
using ll = long long;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
       
        int k=k1+k2;
        vector<int>dif(1e5+1,0);
        for(int i=0; i<n; i++)
        {
            int diff=abs(nums1[i]-nums2[i]);
            dif[diff]++;
        }
     for(int i=1e5; i>0 and k>0; i--)
     {
        int cnt=min(dif[i],k);
        dif[i]-=cnt;
        dif[i-1]+=cnt;
        k-=cnt;

     }
     ll res=0;
     for(int i=1e5; i>0; i--) res+=1ll*dif[i]*i*i;
    return res;
    }
};