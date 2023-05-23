class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int>mp;
        for(auto it:nums2){
            while(stk.size() and stk.top()<it){
                mp[stk.top()]=it;
                stk.pop();
            }
            
            stk.push(it);
        }
        
        vector<int>ans;
        for(auto it:nums1)
            ans.push_back(mp.count(it)? mp[it]:-1);
        
        return ans;
    }
};