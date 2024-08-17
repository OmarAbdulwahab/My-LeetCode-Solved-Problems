class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>jewels_map;
        for(char j:jewels)jewels_map[j]++;
        
        int ans=0;
        for(char s:stones)
            ans += jewels_map[s]>0;
        
        return ans;
    }
};