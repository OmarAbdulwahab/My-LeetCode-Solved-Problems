class Solution {
public:
    string makeGood(string s) {
   //     while(s.size()>1){
   //     bool find=false;
   //     for(int i=0;i<s.size()-1;i++){
   //         if(s[i]==(s[i+1]^0x20)){
   //             s=s.substr(0,i)+s.substr(i+2);
   //             find=true;
   //             break;
   //         }
   //     }
   //     if(!find)break;
   // }
   // return s;
        
        stack<char>stk;
        // for(char c:s){
        //     if(!stk.empty()){
        //         bool small = c-'a'>=0;
        //         if(small){
        //             if(stk.top()-'a' < 0){
        //                 if(stk.top()-c+20 == 0)stk.pop();
        //                 else stk.push(c);
        //             }
        //             else stk.push(c);
        //         }
        //         else{
        //           if(c-stk.top()+20 == 0)stk.pop(); 
        //           else stk.push(c); 
        //         } 
        //     }
        //     else{
        //         stk.push(c);
        //     }
        // }
        for(char c:s){
            if(!stk.empty() and stk.top()!=c and lower(stk.top())==lower(c))
                stk.pop();
            else
                stk.push(c);
        }
        
        string ans="";
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    char lower(char c){
        if(c<'a'){
            return char(c+'a'-'A');
        }
        return c;
    }
};