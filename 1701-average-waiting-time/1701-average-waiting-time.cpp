class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = customers[0][1];
        int S = customers[0][0] + customers[0][1];
        
        for(int i=1; i<customers.size();i++){
            if(customers[i][0] > S){
                total += customers[i][1];
                S = customers[i][0] + customers[i][1];
            }
            else{
                total += (S + customers[i][1] - customers[i][0]);
                S += customers[i][1];
            }
        }
        
        return double(total/customers.size());
    }
};