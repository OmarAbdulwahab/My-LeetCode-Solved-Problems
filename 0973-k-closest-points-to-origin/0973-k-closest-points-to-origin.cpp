class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>>v;
        for(vector<int> point:points){
            int dis = (point[0]*point[0])+(point[1]*point[1]);
            v.push_back({dis, point});
        }
        
        sort(begin(v), end(v));
        vector<vector<int>>ans;
        for(int i=0; i<k; i++)
            ans.push_back(v[i].second);
        
        return ans;
    }
};