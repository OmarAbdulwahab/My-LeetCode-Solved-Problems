class Solution {
public:
    string customSortString(string order, string s) {
        // unordered_map<char,int>mp;
        map<char,int>el;
        // for(int i=0;i<order.size();i++)
        //     mp.insert({order[i],i});
        for(auto c:s)el[c]++;
        string ans="";
        for(char c:order){
            while(el[c]--)ans.push_back(c);
            el.erase(c);
        }
        
        for(auto it:el){
            while(it.second--)ans.push_back(it.first);
        }
        
        return ans;
    }
};