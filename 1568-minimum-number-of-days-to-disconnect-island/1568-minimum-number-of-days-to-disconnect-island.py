class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        def dfs(r, c, visit):
            if( r<0 or c<0  or r == rows or c == cols
                or grid[r][c]==0 or (r,c) in visit):
                return
            visit.add((r,c))
            neighbors = [[r+1,c], [r,c+1],[r-1,c],[r,c-1]]
            for nr, nc in neighbors:
                dfs(nr, nc, visit)
            
        
        def count_islands():
            visit = set()
            count = 0
            for r in range(rows):
                for c in range(cols):
                    if grid[r][c] and (r,c) not in visit:
                        dfs(r,c, visit)
                        count += 1
            return count
                        
        if count_islands() != 1:
            return 0
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==0:
                    continue
                grid[r][c] = 0

                if count_islands() != 1:
                    return 1
                grid[r][c] = 1
        
        
        return 2