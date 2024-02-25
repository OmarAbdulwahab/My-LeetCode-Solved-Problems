class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>answer;
        //sort(nums.begin(),nums.end());
        //int p1=0,p2=nums.size()-1;
        int n=nums.size();
        // bool found=false;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]+nums[j])==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};