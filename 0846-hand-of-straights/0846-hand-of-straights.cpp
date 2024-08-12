class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        
        map<int,int>mp;
        for(int h:hand)mp[h]++;
        
        while(!mp.empty()){
            int element = mp.begin()->first;
            
            for(int i=0; i<groupSize; i++){
                if(mp[element+i]<1)
                    return false;
                mp[element+i]--;
                if(mp[element+i]==0)
                    mp.erase(element+i);
            }
        }
        
        return true;
    }
};