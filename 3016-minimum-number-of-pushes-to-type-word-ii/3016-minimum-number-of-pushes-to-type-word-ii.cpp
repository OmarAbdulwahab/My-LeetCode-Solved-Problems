class Solution {
public:
    int minimumPushes(string word) {
        vector<int> chars(26,0);
        for(char c:word)chars[c-'a']+=1;
        sort(chars.rbegin(), chars.rend());
        
        int ans=0;
        for(int i=0; i<8; i++)ans+= chars[i];
        for(int i=8; i<16; i++)ans+= (chars[i] * 2);
        for(int i=16; i<24; i++)ans+= (chars[i]*3);
        ans+= chars[24]*4;
        ans+= chars[25]*4;
        return ans;
    }
};