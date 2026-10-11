class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0,k=0;
        int ind1=((n+m)/2)-1;
        int ind2=(n+m)/2;
        int element1=-1,element2=-1;
        while(i<n and j<m)
        {
            if(nums1[i] <= nums2[j])
            {
                if(ind1 == k) element1=nums1[i];
                else if(ind2 == k) element2=nums1[i];
                i++;
            }else 
            {
                if(ind1 == k) element1=nums2[j];
                else if(ind2 == k) element2=nums2[j];
                j++;
            }
            k++;
        }
        while(i < n)
        {
            
                if(ind1 == k) element1=nums1[i];
                else if(ind2 == k) element2=nums1[i];
                i++;
                k++;
            
        }
        while(j < m)
        {
            if(ind1 == k) element1=nums2[j];
            else if(ind2 == k) element2=nums2[j];
            j++;
            k++;
        }
        return (n+m)%2==0?(element1+element2)/2.0:element2;
    }
};