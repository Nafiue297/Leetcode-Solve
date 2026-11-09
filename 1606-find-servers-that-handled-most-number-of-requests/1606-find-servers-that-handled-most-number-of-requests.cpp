class Solution {
public:
typedef pair<int,int>P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>freeserver;
        for(int i=0; i<k; i++) freeserver.insert(i);
        priority_queue<P, vector<P>, greater<P>>busyserver;
        vector<int>cnt(k,0);
        vector<int>res;
        for(int i=0; i<arrival.size(); i++)
        {
            int time=arrival[i];
            while(!busyserver.empty() and busyserver.top().first<=time)
            {
               freeserver.insert(busyserver.top().second);
               busyserver.pop();
            }
            int target=i%k;
            auto it=freeserver.lower_bound(target);
            if(it==freeserver.end()) it=freeserver.begin();
            if(freeserver.empty()) continue;
            int server=*it;
            busyserver.push({time+load[i], server});
            freeserver.erase(server);
            cnt[server]++;
            
        }
        int mx=*max_element(begin(cnt), end(cnt));
        for(int i=0; i<k; i++)
        {
            if(cnt[i]==mx) res.push_back(i);
        }
    return res;
    }
};