class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        int cnt=0;
        vector<int>prev[26];
        for(int i=0; i<n; i++) prev[s[i]-'a'].push_back(i);
        for(auto u:words)
        {
            int pre=-1;
            bool possible=true;
        for(auto v:u)
        {
            vector<int>&ans=prev[v-'a'];
            auto it=upper_bound(ans.begin(), ans.end(),pre);
            if(it==ans.end())
            {
                possible =false;
                break;
            }
            pre=*it;
           

        } if(possible) cnt++;
        }
        return cnt;
    }
};