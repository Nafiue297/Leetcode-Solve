class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
       int n=s.size();
       vector<int>start(26,-1);
       vector<int>end(26,-1);
       vector<int>valid(26,true);
       vector<string>result;
       for(int i=0; i<n; i++)
       {
         int ind=s[i]-'a';
         if(start[ind]==-1)start[ind]=i;
         end[ind]=i;
       }
       for(int i=0; i<26; i++)
       {
         if(start[i]==-1) continue;
         for(int j=start[i]; j<=end[i]; j++)
         {
            if(start[s[j]-'a'] < start[i]) 
            {
                valid[i]=false;
                break;
            }
            end[i]=max(end[i], end[s[j]-'a']);
         }
       }
       int last=INT_MAX;
       for(int i=n-1; i>=0; i--)
       {
        int ind=s[i]-'a';
        if(!valid[ind]) continue;
        if(i==start[ind] and end[ind] < last)
        {
            result.push_back(s.substr(i,end[ind]-i+1));
            last=i;
        }

       }
    return result;
    }
};