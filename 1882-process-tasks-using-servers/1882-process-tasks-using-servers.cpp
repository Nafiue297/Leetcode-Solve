class Solution {
public:
typedef pair<int, int>P;
typedef tuple<long, int, int>T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>res(m,0);
        priority_queue<P, vector<P>, greater<P>>freeserver;
        priority_queue<T, vector<T>, greater<T>>busyserver;
        for(int i=0; i<n ;i++) freeserver.push({servers[i], i});
        for(int i=0; i<m; i++)
        {
            while(!busyserver.empty() and get<0>(busyserver.top())<=i)
            {
                auto [fintime, wt, idx]=busyserver.top();
                busyserver.pop();
                freeserver.push({wt, idx});
            }
        if(freeserver.empty())
        {
            auto [fintime, wt, idx]=busyserver.top();
            busyserver.pop();
            res[i]=idx;
            busyserver.push({fintime+tasks[i], wt, idx});
        }
      else
      {
        auto [wt, idx]=freeserver.top();
        freeserver.pop();
        res[i]=idx;
        busyserver.push({i+tasks[i], wt, idx});
      }
        }
    return res;
    }
};