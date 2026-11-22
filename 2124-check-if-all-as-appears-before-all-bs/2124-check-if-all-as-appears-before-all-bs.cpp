class Solution {
public:
    bool checkString(string s) {
       int n=s.size();
      
      int i=0;
      while(s[i]=='a') i++;
      for(int j=i+1; j<n; j++)
      {
        if(s[j]=='a') return false;
      }
     return true;
    }
};