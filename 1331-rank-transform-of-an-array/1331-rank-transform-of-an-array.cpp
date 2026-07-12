class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>v=arr;
       unordered_map<int,int>mp;
       sort(v.begin(),v.end());
       int l=1;
       for(int i=0;i<v.size();i++)
       {
          if(!mp.count(v[i]))
          mp[v[i]]=l++; 
       }
       vector<int>res;
     for(int i=0;i<arr.size();i++)
     {
        res.push_back(mp[arr[i]]);
     }
     return res;


    }
};