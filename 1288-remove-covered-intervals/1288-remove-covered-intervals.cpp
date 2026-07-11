class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
       sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b) {
         if (a[0] != b[0]) return a[0] < b[0];
         return a[1] > b[1];
     });
        int j=0,cnt=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[j][1]<intervals[i][1])j=i;
            else cnt++;
            
             
        }
        return n-cnt;
    }
};