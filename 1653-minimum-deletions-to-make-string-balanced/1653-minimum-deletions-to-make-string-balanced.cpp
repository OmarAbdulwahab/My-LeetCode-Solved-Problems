class Solution {
public:// neetcode amazing solution
    int minimumDeletions(string s) {
        int cost = 0, cnt_b = 0;
        for(char c:s){
            if(c=='a' and cnt_b>0){
                cnt_b--;
                cost++;
            }else if(c=='b'){
                cnt_b++;
            }
        }
        
        return cost;
    }
};