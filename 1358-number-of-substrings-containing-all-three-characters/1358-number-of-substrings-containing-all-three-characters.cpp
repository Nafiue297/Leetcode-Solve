class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int ans = 0;
        int n = s.size();

        unordered_map<char,int> mp;

        for(int high = 0; high < n; high++)
        {
            mp[s[high]]++;

            while(mp.size() == 3)
            {
                ans+=n-high;

                mp[s[left]]--;

                if(mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }
        }

        return ans;
    }
};