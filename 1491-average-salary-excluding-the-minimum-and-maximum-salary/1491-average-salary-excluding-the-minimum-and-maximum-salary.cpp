class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX,mx=INT_MIN;
        for(auto it:salary){
            mn=min(mn,it);
            mx=max(mx,it);
        }
        double sum=0;
        for(auto it:salary){
            if(it!=mn and it!=mx)
                sum+=it;
        }
        
    if(salary.size()==3)return sum;
     
        return sum/(salary.size()-2);
    }
};