class Solution {
public:
    int minLength(string s) {
        stack<char>stk;
        for(char c:s){
            if(stk.size()){
                if((c=='B' and stk.top()=='A')or(c=='D' and stk.top()=='C'))stk.pop();
                else stk.push(c);
            }else stk.push(c);
        }
        
        return stk.size();
    }
};