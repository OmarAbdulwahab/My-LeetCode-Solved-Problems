class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        for(char c:s){
            if(!stk.empty()){
                if(c==')' and stk.top()=='(')stk.pop();
                else stk.push(c);
            }else stk.push(c);
        }
        
        return stk.size();
    }
};