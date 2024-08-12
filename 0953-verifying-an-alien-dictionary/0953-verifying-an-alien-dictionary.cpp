class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>order_map;
        for(int i=0; i<order.size(); i++){
            order_map[order[i]] = i;
        }
        
        for(int i=0; i<words.size()-1; i++){
            for(int j=0; j<words[i].size(); j++){
                if(j >= words[i+1].size())// like: {"apple", "app"}
                    return false;
                
                if(words[i][j] != words[i+1][j]){
                    if(order_map[words[i][j]] > order_map[words[i+1][j]])
                        return false;
                    break;
                }
            }
        }
        
        return true;
    }
};