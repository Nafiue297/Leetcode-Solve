class Solution {
public:
bool vowel(char s)
{
    if(s=='a' or s=='e' or s=='i' or s=='o' or s=='u' or s=='A' or s=='E' or s=='I' or s=='O' or s=='U')return true;
    return false;
}
    string sortVowels(string s) {
        
        string v;
        for(int i=0;i<s.size();i++)
        {
            if(!vowel(s[i]))continue;
              v.push_back(s[i]);
              s[i]='*';
        }
        sort(v.begin(),v.end());
        int p=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')s[i]=v[p++];
        }
        return s;
    }
};