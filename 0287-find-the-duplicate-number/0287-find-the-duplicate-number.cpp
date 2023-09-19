class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]])return nums[i];
            mp[nums[i]]++;
        }
    
    return 0;
    }
};