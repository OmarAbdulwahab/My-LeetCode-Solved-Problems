class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
//         vector<int>even,odd;
//         for(auto it:nums)
//             it&1?odd.push_back(it):even.push_back(it);
        
//         vector<int>ans;
//         for(auto it:even)ans.push_back(it);
//         for(auto it:odd)ans.push_back(it);
        
        deque<int>dq;
        for(int num:nums)
            num&1?dq.push_back(num):dq.push_front(num);
        
        vector<int>ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        
        return ans;
    }
};