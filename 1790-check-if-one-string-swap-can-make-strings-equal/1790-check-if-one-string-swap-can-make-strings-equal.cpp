class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        
        int cnt=0;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]!=s1[i])cnt++;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1!=s2)return false;
        return cnt==2;
    }
};