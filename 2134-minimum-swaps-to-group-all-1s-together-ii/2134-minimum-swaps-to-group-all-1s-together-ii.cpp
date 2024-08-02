class Solution {
public://neetcode
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;
        for(int n:nums) total_ones += n;
        
        int l = 0;
        int window_ones = 0;
        int max_window_ones = 0;
        for(int r=0; r< 2*n; r++){
            if(nums[r % n])
                window_ones++;
            if(r - l + 1 > total_ones){
                window_ones -= nums[l % n];
                l++;
            }
            max_window_ones = max(max_window_ones, window_ones);
        }
        
        
        return total_ones - max_window_ones;
    }
};