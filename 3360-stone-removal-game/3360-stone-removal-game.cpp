class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
         int cnt=10,turn=1;
         while(n)
         {
            if(turn%2==1)
            {
                if(n<cnt) break;
                n-=cnt;
                cnt--;
                turn++;
            }else
            {
                if(n<cnt) break;
                n-=cnt;
                cnt--;
                turn++;
            }
         }

    if(turn%2==0) return true;
    return false;

    }
};