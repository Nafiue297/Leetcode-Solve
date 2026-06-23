class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto u:s)
        {
            if(!ans.empty() and u=='*')ans.pop_back();
            if(ans.empty() and u=='*')continue;
            else if(u!='*') ans.push_back(u);
        }
        return ans;
    }
};