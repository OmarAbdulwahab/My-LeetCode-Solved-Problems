class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        for i, n in enumerate(nums):
            nums[i] = str(n)
            
        
        def compare(n1, n2):
            if n1 + n2 > n2 + n1:
                return -1
            else:
                return 1
        
        nums = sorted(nums, key = cmp_to_key(compare))
        # if we have [0,0,0] the result will be "000" but we want "0" 
        # so we convert "000" to integer so it becomes 0 then change it again to string to be "0"
        return str(int("".join(nums)))