class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
       int cnt=0;
       for(auto u:patterns)
       {
         cnt+=word.find(u)!=-1;
       } 
       return cnt;
    }
};