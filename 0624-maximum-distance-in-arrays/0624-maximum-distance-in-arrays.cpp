class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn=arrays[0][0], mx = arrays[0][arrays[0].size()-1];
        int ans=INT_MIN;
        for(int i=1; i<arrays.size();i++){
            int cur_mn = abs(mn - arrays[i][arrays[i].size()-1]);
            int cur_mx = abs(mx - arrays[i][0]);
            int cur_ans = max(cur_mn, cur_mx);
            
            ans = max(ans, cur_ans);
            
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i][arrays[i].size()-1]);
        }
        
        return ans;
    }
};