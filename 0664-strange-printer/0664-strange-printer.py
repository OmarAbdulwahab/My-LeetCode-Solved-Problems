class Solution:# Larry # really hard problem
    def strangePrinter(self, s: str) -> int:
        N = len(s)
        INF = 10 ** 20
                
        # left, right inclusive
        # minimum to print left, right
        @cache
        def paint_min(left, right, free):
            if left > right:
                return 0
            
            # if the first character is equal to the free one we just chop it off
            if s[left] == free:
                return paint_min(left+1, right, free)
            
            # if it is not, that means that we need to do a new series in the middle
            best = INF
            new_free = s[left]
            best = min(best, paint_min(left, right, new_free)+1)
            for i in range(left, right+1):
                if s[i]==free:
                    best = min(best, paint_min(left, i-1, new_free) + 1 + paint_min(i+1, right, free))
                
            return best
        
        return paint_min(0, N-1, '')
        
        