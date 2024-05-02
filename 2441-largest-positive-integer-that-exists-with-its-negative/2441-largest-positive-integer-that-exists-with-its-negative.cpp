class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums)mp[num]++;
        
        sort(begin(nums), end(nums));
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]<0)return -1;
            if(mp[nums[i]* -1]>=1)return nums[i];
        }
        
        return -1;
    }
};