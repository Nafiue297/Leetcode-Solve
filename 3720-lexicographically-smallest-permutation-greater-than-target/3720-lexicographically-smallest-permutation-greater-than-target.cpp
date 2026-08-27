class Solution {
public:
   string ans="";
   bool solve(string &curr, vector<int>&cnt, int i, string &target, bool greater)
   {
      if(i==target.size())
      {
         if(greater)
         {
            ans=curr;
            return true;
         }
         return false;
      }
     
      for(char ch='a'; ch<='z'; ch++)
      {
           if(cnt[ch-'a']==0)continue;
           if(greater==false and ch<target[i])continue;
           curr.push_back(ch);
           cnt[ch-'a']--;
        bool isgreater=greater or ch>target[i];
        if(solve(curr, cnt, i+1, target, isgreater)==true)return true;
        curr.pop_back();
        cnt[ch-'a']++;
      }
      return false;


   }
    string lexGreaterPermutation(string s, string target) {
       vector<int>cnt(26,0);
       for(auto u: s)cnt[u-'a']++;
       string curr;
       
       solve(curr, cnt, 0, target, false);
       return ans;

    }
};