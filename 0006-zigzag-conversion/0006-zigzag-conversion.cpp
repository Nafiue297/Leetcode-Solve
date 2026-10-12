class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1 or numRows>=n) return s;
        vector<vector<char>>v(numRows);
        int idx=0;
        int j=0;
        for(int i=0; i<n; i++)
        {
            v[j].push_back(s[i]);
            if(j==0) idx=1;
            else if(j==numRows-1) idx=-1;
            j+=idx;
        }
        string res;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[i].size(); j++)
            res+=v[i][j];
        }
    return res;
    }
};