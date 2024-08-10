class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int row = 0; row < n-2; row++) {
            for (int col = 0; col < m-2; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // Ensure 1 - 9
        set<int> values;
        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(values.find(grid[i][j])!= values.end() or grid[i][j]<1 or grid[i][j]>9)
                    return false;
                values.insert(grid[i][j]);
            }
        }
        // rows
        for(int i=row; i<row+3; i++){
            int row_sum = grid[i][col] + grid[i][col+1] + grid[i][col+2];
            if(row_sum != 15)
                return false;
        }
        // cols
        for(int i=col; i<col+3; i++){
            int col_sum = grid[row][i] + grid[row+1][i] + grid[row+2][i];
            if(col_sum != 15)
                return false;
        }
        // diagonals
        int d1_sum = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int d2_sum = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if((d1_sum != 15) or (d2_sum != 15)) return false;
        
        // all is ok: it is a magic square
        return true;
    }
};