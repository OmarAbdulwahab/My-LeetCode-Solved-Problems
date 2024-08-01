class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string d:details){
            char d1= d[11];
            char d2 = d[12];
            ans+= ((d1-'0')*10 + (d2-'0'))>60;
        }
        
        return ans;
    }
};