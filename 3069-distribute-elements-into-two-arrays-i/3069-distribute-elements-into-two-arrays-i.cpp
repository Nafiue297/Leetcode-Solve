class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2,res;
        int n=nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
       for(int i=2; i<n; i++)
       {
        if(arr1.back()>arr2.back())arr1.push_back(nums[i]);
        else arr2.push_back(nums[i]);
       }
       
      for(auto u:arr1)res.push_back(u);
      for (auto u:arr2)res.push_back(u);
       return res;
        
    }
};