class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>mp;
        for(auto &u:reservedSeats)
        {
            int row=u[0];
            int seat=u[1];
            mp[row]|=(1<<seat);
        }
        int res=(n-mp.size())*2;
        int maska=(1<<2)|(1<<3)|(1<<4)|(1<<5);
        int maskb=(1<<4)|(1<<5)|(1<<6)|(1<<7);
        int maskc=(1<<6)|(1<<7)|(1<<8)|(1<<9);
     for(auto [u,v]:mp)
     {
        bool a=(maska & v)==0;
        bool b=(maskb &v)==0;
        bool c=(maskc &v)==0;
        if(a and c)res+=2;
        else if(a or b or c)res++;
     }
     return res;
    }
};