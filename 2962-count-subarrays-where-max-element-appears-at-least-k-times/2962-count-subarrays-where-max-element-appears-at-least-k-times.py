class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx, cnt = max(nums), 0
        l = 0
        ans = 0
        
        for r in range(len(nums)):
            if nums[r] == mx:
                cnt += 1
            # this is another way to write it
            while cnt == k:
                if nums[l] == mx:
                    cnt -= 1
                l += 1
            ans += l
#             while cnt > k or (cnt == k and nums[l] != mx and l<=r):
#                 if nums[l] == mx:
#                     cnt -= 1
#                 l += 1
            
#             if cnt == k:
#                 ans += l+1
                
        return ans