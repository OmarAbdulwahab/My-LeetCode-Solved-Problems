class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // My solution ;) after 2 hours
        int n = positions.size();
        // robots: {position, {{number, health}, direction}}
        vector<vector<int>> robots(n, vector<int>(4));
        // robots[i][0] = position
        // robots[i][1] = number
        // robots[i][2] = health
        // robots[i][3] = direction
        map<int,int>mp;
        // map: number -> health
        for(int i=0; i<n; i++){
            robots[i][0] = positions[i];
            robots[i][1] = i+1;
            robots[i][2] = healths[i];
            robots[i][3] = directions[i];
            
            mp[i+1] = healths[i];
        }
        sort(robots.begin(), robots.end());
        
        stack<vector<int>>stk;
        for(int i=0; i<n ; i++){
            if(stk.empty()){
                stk.push(robots[i]);
                continue;
            }
            
            while(!stk.empty() and  stk.top()[3] == 'R' and robots[i][3] == 'L'){
                int curNumber = robots[i][1];
                int curHealth = robots[i][2];

                int topNumber = stk.top()[1];
                int topHealth = stk.top()[2];
                
                if(curHealth > topHealth){ // cur > top
                    mp[curNumber]--;
                    robots[i][2] -= 1; // curHealth -= 1
                    topHealth = 0;
                    mp[topNumber] = 0;
                    stk.pop();
                }else if(curHealth < topHealth){ // cur < top
                    mp[topNumber]--;
                    stk.top()[2] -= 1; // topHealth -= 1
                    curHealth=0;
                    robots[i][2] = 0;
                    mp[curNumber] = 0;
                    break;
                }else{ // cur == top
                    mp[curNumber] = 0;
                    mp[topNumber] = 0;
                    robots[i][2] = 0;
                    stk.top()[2] = 0;
                    stk.pop();
                    break;
                }
            }
            if(robots[i][2]>0)
                stk.push(robots[i]);
        }
        
        vector<int> ans;
        for(auto it:mp){
            if(it.second != 0)
                ans.push_back(it.second);
        }
        
        return ans;
    }
};