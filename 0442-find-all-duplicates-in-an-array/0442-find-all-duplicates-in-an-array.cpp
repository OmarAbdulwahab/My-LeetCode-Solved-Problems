class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // neetcode: now let's solve it using time:O(n) and space:O(1);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int indx = abs(nums[i])-1;
            if(nums[indx]<0)ans.push_back(indx+1);
            else nums[indx]*=-1;
        }
        
        return ans;
    }
};