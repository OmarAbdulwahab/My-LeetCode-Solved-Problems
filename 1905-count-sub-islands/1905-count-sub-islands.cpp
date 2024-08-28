class Solution {
public:
    // DFS: O{n*m} time and space
    set<pair<int,int>> visit;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid1[0].size();
        
        
        int ans = 0;
        for(int r = 0; r<rows; r++){
            for(int c = 0; c<cols; c++){
                if(grid2[r][c] and visit.find({r,c})==visit.end() and dfs(r,c, grid1, grid2))
                    ans++;
            }
        }
        
        return ans;
    }
    
private:
    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(r < 0 or c < 0 or r == grid1.size() or c == grid1[0].size() or visit.find({r,c}) != visit.end() or grid2[r][c]==0)
            return true; // not meaning that this island is not a sub-island
        
        visit.insert({r,c});
        bool res = true;
        if(grid1[r][c]==0)
            res = false; // this means that this island is not a sub-island
        
        // now we want to go through the island and if any cell return false then this island is not a sub-island
        res = dfs(r-1,c, grid1, grid2) && res;
        res = dfs(r+1,c, grid1, grid2) && res;
        res = dfs(r,c-1, grid1, grid2) && res;
        res = dfs(r,c+1, grid1, grid2) && res;
        
        return res;

    }
};