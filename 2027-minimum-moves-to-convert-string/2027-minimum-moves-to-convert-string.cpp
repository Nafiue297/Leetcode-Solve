class Solution {
public:
    int minimumMoves(string s) {
    int cnt=0;
    int n=s.size();
    for(int i=0; i<n;)
    {
        if(s[i]=='X')
        {
            cnt++;
            i+=3;
        }else i++;
       
    }
    return cnt;
    }
};