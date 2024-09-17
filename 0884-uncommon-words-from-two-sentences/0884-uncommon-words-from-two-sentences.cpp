class Solution {
public:
    map<string, int> mp;
    vector<string> uncommonFromSentences(string s1, string s2) {
        split(s1);
        split(s2);
        
        vector<string> ans;
        for(auto it:mp)
            if(it.second==1)ans.push_back(it.first);
        
        return ans;
    }
    
private:
    void split(string s){
        string tmp = "";
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                mp[tmp]++;
                tmp = "";
                i++;
                continue;
            }
            tmp += s[i];
            i++;
        }
        mp[tmp]++;
    }
};