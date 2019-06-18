__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def trap(self, height: List[int]) -> int:
        
        ans = 0
        left = 0
        right = len(height) - 1
        
        if len(height) == 0:
            return 0
        
        
        left_max = height[left]
        right_max = height[right]
        
        while left <= right:
            if height[left] <= height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    ans += left_max - height[left]
                    
                left += 1
                
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    ans += right_max - height[right]
                    
                right -= 1
                
        return ans
__________________________________________________________________________________________________
sample 13016 kb submission
class Solution:
    def trap(self, height: List[int]) -> int:
        i, j = 0, len(height)-1
        water = left_max = right_max = 0
        
        while i < j:
            if height[i] < height[j]:
                left_max = max(left_max, height[i])
                water += left_max - height[i]
                i += 1
            else:
                right_max = max(right_max, height[j])
                water += right_max - height[j]
                j -= 1
        return water
__________________________________________________________________________________________________
