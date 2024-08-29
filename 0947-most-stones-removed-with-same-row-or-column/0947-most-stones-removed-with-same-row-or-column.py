class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        # Union-Fjnd
        N = len(stones)
        
        parents = [i for i in range(N)]
        
        def ufind(x):
            if parents[x] != x:
                parents[x] = ufind(parents[x])
            return parents[x]
        
        def uunion(a, b):
            ua = ufind(a)
            ub = ufind(b)
            
            parents[ua] = ub
        
        xs = collections.defaultdict(list)
        ys = collections.defaultdict(list)
        
        for index, (x, y) in enumerate(stones):
            xs[x].append(index)
            ys[y].append(index)
            
        for x in xs.keys():
            index = xs[x][0]
            for index2 in xs[x][1:]:
                uunion(index, index2)
                
        for y in ys.keys():
            index = ys[y][0]
            for index2 in ys[y][1:]:
                uunion(index, index2)
                
        s = set()
        for index in range(N):
            s.add(ufind(index))
            
            
        return N - len(s)
            
            
            
            
            
            