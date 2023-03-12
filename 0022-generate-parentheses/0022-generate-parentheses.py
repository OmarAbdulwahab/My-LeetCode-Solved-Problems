class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # recursive backtracking
        # number of left or right parens
        def recur(l,r,path):
            if len(path) == n*2:
                self.arr.append(''.join(path))
                return
            if l < n:
                # recursive backtracking
                # adding left paren
                path.append('(')
                recur(l+1,r,path)
                del path[-1]
            if r < l:
                path.append(')')
                recur(l,r+1,path)
                del path[-1]
                
                
        self.arr=[]
        recur(0,0,[])
        return self.arr