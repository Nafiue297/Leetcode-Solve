class Solution {
public:
char mid='$';
int half=0;
string ans="";
bool solve(string& curr,vector<int>&cnt, string& target, int i, bool greater)
{
    if(curr.size()== half)
    {
        string lefthalf=curr;
        string righthalf=curr;
        reverse(begin(righthalf),end(righthalf));
        if(mid!='$')lefthalf+=mid;
        lefthalf+=righthalf;
        if(lefthalf > target)
        {
            ans=lefthalf;
            return true;
        }
        return false;
    }
    for(char ch='a'; ch<='z'; ch++)
    {
        if(cnt[ch-'a']==0) continue;
        if(!greater and ch < target[i]) continue;
        
        curr.push_back(ch);
        cnt[ch-'a']--;
    bool isgreater=greater or ch > target[i];
    if(solve(curr, cnt, target, i+1, isgreater)==true) return true;
    
     curr.pop_back();
     cnt[ch-'a']++;
    }
  return false;
}
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>cnt(26,0);
        int odd=0;
        for(auto u:s)cnt[u-'a']++;
        for(int i=0; i<26; i++)
        {
            if(cnt[i]%2==1)
            {
              odd++;
              mid=i+'a';
            }
            
        }
        if(odd>1)return "";
        for(int i=0; i<26; i++)cnt[i]/=2;
         half=n/2;
         string curr;
     solve(curr, cnt, target, 0, false);
     return ans;
    }
};