class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        int cnt=1;
        for(int i=0; i<n; i++)
        {
            int ind=s[i]-'a';
            ind=26-ind;
            ind*=cnt++;
            sum+=ind;
        }
        return sum;
    }
};