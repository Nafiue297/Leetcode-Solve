class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int mx=-1;
        while(i < j)
        {
            int mini=min(height[i],height[j]);
            mx=max(mx,mini*(j-i));
            if(height[i] <= height[j]) i++;
            else j--;

        }
        return mx;
    }
};