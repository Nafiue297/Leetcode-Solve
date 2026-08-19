class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
     unordered_map<int,unordered_set<int>>mp;
     for(int i=0; i<reservedSeats.size(); i++)
     {
        int row=reservedSeats[i][0];
        int col=reservedSeats[i][1];
        mp[row].insert(col);
     }
     int result=(n-mp.size())*2;
     for(auto[i,j]:mp)
     {
        auto valid=[&](int seats){
         return j.find(seats)==j.end();
        };
        bool a=valid(2) and valid(3) and valid(4) and valid(5);
        bool b=valid(4) and valid(5) and valid(6) and valid(7);
        bool c=valid(6) and valid(7) and valid(8) and valid(9);
        if(a and c)result+=2;
        else if(a or b or c)result++;
     }
     return result;
    }
};