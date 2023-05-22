class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<pair<int,int>>v;
        for(auto [n,cnt]:mp){
            v.push_back({cnt,n});
        }
        sort(v.begin(),v.end(),greater<>());
        vector<int>ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        
        
        return ans;
    }
};