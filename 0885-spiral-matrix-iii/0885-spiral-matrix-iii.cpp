class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int steps = 1;
        int r = rStart, c = cStart;
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int i=0;
        
        while(ans.size() < rows*cols){// ans will only contains valid cells
            for(int j=0; j<2; j++){
                int dr = directions[i].first, dc = directions[i].second;
                for(int k=0; k<steps; k++){
                    if(r<rows and r>=0 and c<cols and c>=0)
                        ans.push_back({r,c});
                    r+= dr;
                    c+= dc;
                }
                i = (i+1)%4;
            }
            steps++;
        }
        
        
        return ans;
    }
};