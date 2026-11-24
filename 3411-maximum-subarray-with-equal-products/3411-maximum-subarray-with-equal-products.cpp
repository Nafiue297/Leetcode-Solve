class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long mul = 1;
        int len = 2;

        for (int right = 0; right < n; right++) {
             while(gcd(mul,nums[right])>1)
             {
                  mul/=nums[left++];
             }
             mul*=nums[right];
            len = max(len, right - left + 1);
        }

        return len;
    }
};