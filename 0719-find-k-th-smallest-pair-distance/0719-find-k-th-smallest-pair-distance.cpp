class Solution {
public://neetcode
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r=nums[nums.size()-1];// r = max element in nums
        
        while(l<r){
            int mid = l + ((r-l)/2);
            int pairs = count_pairs(mid, nums);
            
            if(pairs >= k)
                r = mid;
            else
                l = mid+1;
        }
        
        return r;
    }
    
private:
    int count_pairs(int diff, vector<int>& nums){
        int pairs = 0;
        int l=0;
        
        for(int r=0; r<nums.size(); r++){
            while(nums[r] - nums[l] > diff)
                l++;
            
            pairs+= r-l; // length of the window
        }
        
        return pairs;
    }
};