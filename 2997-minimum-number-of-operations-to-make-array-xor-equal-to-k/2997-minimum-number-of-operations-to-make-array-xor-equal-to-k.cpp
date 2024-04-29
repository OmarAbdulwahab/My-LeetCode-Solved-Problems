class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(int c:nums)
            x ^= c;
        
        int count = 0;
        for(int i=0; i<22; i++){
            if( ((x & (1<<i)) > 0) != ((k & (1<<i)) > 0))
                count++;
        }
        
        return count;
    }
};