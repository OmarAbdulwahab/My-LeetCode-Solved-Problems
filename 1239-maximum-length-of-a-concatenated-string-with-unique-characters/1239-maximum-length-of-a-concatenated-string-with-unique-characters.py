class Solution:
    def maxLength(self, arr: List[str]) -> int:
        charSet = set()
        
        def overlap(charSet, s):
            c = Counter(charSet) + Counter(s)
            return max(c.values())>1
        
        
        def backtrack(i):
            if i == len(arr):
                return len(charSet)
            
            ans=0
            if not overlap(charSet,arr[i]):
                for c in arr[i]:
                    charSet.add(c)
                ans = backtrack(i+1)
                for c in arr[i]:
                    charSet.remove(c)
            return max(ans, backtrack(i+1))
        
        return backtrack(0)