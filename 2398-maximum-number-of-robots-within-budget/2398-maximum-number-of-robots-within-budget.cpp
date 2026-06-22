class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left=0;
        long long sum=0;
        deque<int>dq;
        int ans=0;
        for(int right=0;right<chargeTimes.size();right++)
        {
            sum+=runningCosts[right];
            while(!dq.empty() and dq.back()<chargeTimes[right])dq.pop_back();
            dq.push_back(chargeTimes[right]);
            long long total=sum*(right-left+1)+dq.front();
            while(total>budget)
            {
                sum-=runningCosts[left];
                if(chargeTimes[left]==dq.front())dq.pop_front();
                left++;
                total=sum*(right-left+1)+dq.front();
                
                

            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};