class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp1, mp2;
        for(int t:target)mp1[t]++;
        for(int a:arr)mp2[a]++;
        
        for(auto it:mp1){
            if(it.second != mp2[it.first])
                return false;
        }
        
        return true;
    }
};