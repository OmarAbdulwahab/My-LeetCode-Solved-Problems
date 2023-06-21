class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto it:edges){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        
        int t = INT_MIN, ans;
        for(auto [f,s]:mp)
            if(s>ans){
                ans=f;
                t=s;
            }
            
        
        return ans;
    }
};