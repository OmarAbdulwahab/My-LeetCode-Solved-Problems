class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int e=0;
        while(num>0){
            if(num%2==0)// zero in the original is 1 in the complement
                ans += pow(2,e);
            e++;
            num/=2;
        }
        
        return ans;
    }
};