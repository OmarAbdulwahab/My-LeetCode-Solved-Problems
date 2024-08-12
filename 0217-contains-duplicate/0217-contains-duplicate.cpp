class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int n:nums){
            if(mp[n])return true;
            mp[n]++;
        }
        
        return false;
    }
};