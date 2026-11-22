class Solution {
public:
    bool checkString(string s) {
       int n=s.size();
       bool f=false;
       for(int i=0; i<n; i++)
       {
        if(s[i]=='b' and !f)f=true;
        if(s[i]=='a' and f) return false;
       }
       return true;
      
    }
};