class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        # time: logn, space: n
        ans = []
        
        def dfs(cur):
            if cur > n:
                return
            ans.append(cur)
            for i in range(10):
                dfs(cur * 10 + i)
        
        for i in range(1,10):
            dfs(i)
        return ans