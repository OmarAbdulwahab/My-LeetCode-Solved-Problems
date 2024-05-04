class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        
        int ans=0;
        int left = 0, right = people.size()-1;
        
        while(left<=right){
            if(people[left] + people[right] <= limit){
                ans++;
                left++;
                right--;
            }else{
                ans++;
                right--;
            }
        }
        
        return ans;
//         for(int i=0; i<people.size()-1; i++){
//             cur = people[i];
//             int left = i+1;
//             while(left<people.size() and cur+people[left]<=limit and people[left]!=0){
//                 cur+= people[left];
//                 people[left] = 0;
//                 left++;
//             }
//             ans++;
            
//             // if(cur+people[i]>=limit){
//             //     ans++;
//             //     cur = (cur+people[i]==limit)?0:people[i];
//             // }
//             // else{
//             //     cur+=people[i];
//             // }
//         }
        
        // if(cur!=0)ans++;
        
        return ans;
    }
};