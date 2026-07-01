class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        string ans;
        string tmp;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(tmp.empty()) continue;   // Skip multiple spaces

                reverse(tmp.begin(), tmp.end());

                if(!ans.empty()) ans += ' '; // Add one space only

                ans += tmp;
                tmp.clear();
            }
            else
            {
                tmp += s[i];
            }
        }

        // Process the last word
        if(!tmp.empty())
        {
            reverse(tmp.begin(), tmp.end());

            if(!ans.empty()) ans += ' ';

            ans += tmp;
        }

        return ans;
    }
};