class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string reverseVowels(string s) {
        stack<char>stk;
        for(int i=0; i<s.size();i++){
            if(isVowel(s[i]))stk.push(s[i]);
        }
        
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=stk.top();
                stk.pop();
            }
        }
        
        return s;
    }
};