bool compare(string a, string b){
        return a + b > b + a;
    }

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> string_nums;
        for(int n:nums)
            string_nums.push_back(to_string(n));
        
        sort(begin(string_nums), end(string_nums), compare);
        
        string ans;
        for(string s: string_nums)
            ans+= s;
        
        return ans[0]=='0'? "0": ans;
    }
};