class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<int> subs;
        for(int i=0; i<nums.size(); i++){
            int tmp = 0;
            for(int j=i; j<nums.size(); j++){
                tmp = (tmp + nums[j]) % MOD;
                subs.push_back(tmp);
            }
        }
        sort(subs.begin(), subs.end());
        
        int ans=0;
        for(int i=left-1; i<=right-1; i++)
            ans = (ans + subs[i]) % MOD;
        
        return ans;
    }
};