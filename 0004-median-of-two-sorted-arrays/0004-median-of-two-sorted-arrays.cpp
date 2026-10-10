class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int size=n+m;
        vector<int>res(size);
        int i=0, j=0,k=0;
        while(i<n and j<m)
        {
            if(nums1[i] <= nums2[j])
            {
                res[k++]=nums1[i++];
            }else res[k++]=nums2[j++];
        }
        while(i<n) res[k++]=nums1[i++];
        while(j<m) res[k++]=nums2[j++];
        return ((size%2==0)?(res[size/2]+res[size/2-1])/2.0:res[size/2]);
    }
};