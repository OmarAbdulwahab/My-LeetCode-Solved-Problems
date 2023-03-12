class Solution:
    def maxArea(self, height: List[int]) -> int:
        # two pointer approach
        
        i=0
        j=len(height)-1
        max_water=0
        while i<j:
            water=min(height[i],height[j])*(j-i)
            max_water=max(water,max_water)
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
                
        return max_water
                    