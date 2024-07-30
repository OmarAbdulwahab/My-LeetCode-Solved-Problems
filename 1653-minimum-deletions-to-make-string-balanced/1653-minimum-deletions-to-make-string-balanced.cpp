class Solution {
public:// neetcode amazing solution
    int minimumDeletions(string s) {
        vector<int> a_count_right(s.length(),0);//pre-prossesing
        for(int i=s.size()-2; i>=0; i--)
            a_count_right[i] += (a_count_right[i+1] + (s[i+1]=='a'));
        
        int b_count = 0;
        int ans = INT_MAX;
        for(int i=0; i<s.size(); i++){
            ans = min(ans, a_count_right[i] + b_count);
            b_count+= s[i]=='b';
        }
        
        return ans;
    }
};