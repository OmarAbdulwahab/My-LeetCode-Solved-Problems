class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>stk;
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push(i);
            else if(s[i]==')'){
                int top = stk.top();
                stk.pop();
                reverse(s.begin()+top+1, s.begin()+i);
            }
        }
        
        for(auto ch:s){
            if(ch!='(' and ch!=')')
                res.push_back(ch);
        }
        
        
        return res;
    }
};