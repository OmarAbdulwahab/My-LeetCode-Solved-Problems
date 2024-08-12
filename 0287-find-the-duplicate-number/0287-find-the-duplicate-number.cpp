class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int n:nums){
            if(mp[n])return n;
            mp[n]++;
        }
        
        return 0;
    }
};