class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1, ver2;
        ver1 = convert(version1);
        ver2 = convert(version2);
        
        while(ver1.size() < ver2.size())
            ver1.push_back(0);
        while(ver2.size() < ver1.size())
            ver2.push_back(0);
        
        for(int i=0; i<ver1.size(); i++){
            if(ver1[i] > ver2[i])return 1;
            else if(ver1[i] < ver2[i]) return -1;
        }
        
        return 0;
        
        
        int i=0;
        while(i<ver1.size() or i<ver1.size()){
            if(ver1[i]<ver2[i])return -1;
            else if(ver1[i]>ver2[i])return 1;
            
            i++;
        }
        int j=i;
        while(i<ver1.size()){
            if(ver1[i++]>0)return 1;
        }
        
        while(j<ver2.size()){
            if(ver2[j++]>0)return -1;
        }
        
        return 0;
    }
private:
    vector<int> convert(string str){
        vector<int> res;
        
        string tmp = "";
        for(char c:str){
            if(c == '.'){
                int num = stoi(tmp);
                tmp = "";
                res.push_back(num);
            }else tmp.push_back(c);
        }
        // if(tmp!=""){
            int numr = stoi(tmp);
            res.push_back(numr);
        // }
        return res;
    }
};