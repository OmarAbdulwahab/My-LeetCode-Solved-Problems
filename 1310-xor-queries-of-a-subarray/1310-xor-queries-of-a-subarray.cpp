class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=0; i<n; i++){
            prefix[i+1] = arr[i] ^ prefix[i];
        }
        
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans.push_back(prefix[r+1] ^ prefix[l]);
        }
        
        return ans;
    }
};