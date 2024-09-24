class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        if len(arr1) > len(arr2):
            arr1, arr2 = arr2, arr1
            
        prefix_set = set()
        for n in arr1:
            while n and n not in prefix_set:
                prefix_set.add(n)
                n = n//10
                
        ans = 0
        for n in arr2:
            while n and n not in prefix_set:
                n = n//10
                
            if n in prefix_set:
                ans = max(ans, len(str(n)))
                
        return ans
                