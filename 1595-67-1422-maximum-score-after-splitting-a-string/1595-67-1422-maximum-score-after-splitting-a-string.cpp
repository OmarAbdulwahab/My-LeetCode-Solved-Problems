class Solution {
public:
    int maxScore(string s) {
        int zeros=0, ones=0;
        for(char c:s)ones+= c=='1';
        int n = s.length();
        int ans=0;
        for(int i=0; i< n-1; i++){
            if(s[i]=='0') zeros++;
            else ones--;
            ans = max(ans, ones + zeros);
        }

        return ans;
    }
};