class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        for(char c:allowed)mp[c]++;
        
        int ans=0;
        
        for(int i=0; i<words.size(); i++){
            int found=1;
            for(int j=0; j<words[i].size(); j++){
                if(mp[words[i][j]]<1){
                    found=0;
                    continue;
                }
            }
            ans+=found;
        }
        
        return ans;
    }
};