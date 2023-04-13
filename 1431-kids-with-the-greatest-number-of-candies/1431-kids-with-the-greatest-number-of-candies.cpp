class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=*max_element(candies.begin(),candies.end());
        vector<bool>ans(candies.size());
        for(int i=0;i<candies.size();i++){
            ((candies[i]+extraCandies)>=mx)?ans[i]=true:ans[i]=false;
        }
        
        return ans;
    }
};