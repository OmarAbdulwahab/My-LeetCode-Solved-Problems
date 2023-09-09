class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        if(count(nums.begin(),nums.end(),nums[0])==n)return 0;
        
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        return n-(count(nums.begin(),nums.end(),mx) + count(nums.begin(),nums.end(),mn));
    }
};