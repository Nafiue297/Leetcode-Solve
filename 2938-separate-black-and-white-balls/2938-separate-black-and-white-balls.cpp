class Solution {
public:
typedef long long ll;
    long long minimumSteps(string s) {
       ll cnt=count(begin(s),end(s),'0');
       vector<int>v(cnt,0);
       int cnt1=0;
       int pt=0;
     for(int i=0; i<s.size(); i++)
     {
        if(s[i]=='0')
        {
            v[pt]=cnt1;
            pt++;
        } else cnt1++;
     }
     ll res=0;
    for(int i=0; i<v.size(); i++) res+=v[i];
    return res;
    }
};