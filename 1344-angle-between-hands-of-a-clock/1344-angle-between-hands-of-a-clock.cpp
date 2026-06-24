class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=minutes*6;
        double h=30*(hour%12)+0.5*minutes;
        double diff=abs(h-m);
        return min(360-diff,diff);
    }
};