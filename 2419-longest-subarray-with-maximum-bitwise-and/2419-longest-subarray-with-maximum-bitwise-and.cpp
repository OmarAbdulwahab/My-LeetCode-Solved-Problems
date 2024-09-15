class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // the only sub array that will make the max AND is the contiguos numbers of the max number in the array
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int size = 0;
        for(int n:nums){
            if(n==mx)
                size++;
            else
                size = 0;
                
            ans = max(ans, size);
        }
        
        return ans;
    }
};