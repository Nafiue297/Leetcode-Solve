class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
     int small=*min_element(nums1.begin(), nums1.end());
     if(small % 2== 1) return true;
     for(int i=0; i<nums1.size(); i++)
     {
        if(nums1[i] == small)continue;
        if(nums1[i] % 2== 1) return false;
     }
     return true;

    }
};