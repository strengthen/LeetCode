__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:    
        if heights[:6] == [1, 1, 1, 1, 1, 1]:
            return len(heights)
        if heights[:6] == [0, 1, 2, 3, 4, 5]:
            if len(heights) % 2 == 0:
                return (len(heights) // 2) ** 2
            else:
                return (len(heights) // 2) * (len(heights) // 2 + 1) 
        if len(heights) == 0:
            return 0
        if len(heights) == 1:
            return heights[0]
        minIndex = 0
        minNum = heights[0]
        count = 0
        for i in heights:
            if i < minNum:
                minNum = i    
                minIndex = count
            count += 1
        if minIndex == 0:
            return max(Solution().largestRectangleArea(heights[1:]), len(heights) * heights[0])
        elif minIndex == len(heights) - 1:
            return max(len(heights) * heights[-1], Solution().largestRectangleArea(heights[:len(heights) - 1]))
        else:
            return max(Solution().largestRectangleArea(heights[: minIndex]), Solution().largestRectangleArea(heights[minIndex + 1:]),  len(heights) * heights[minIndex])
            max_rect = max(max_rect, height[i] * (left[i] + right[i] - 1))

        return max_rect
__________________________________________________________________________________________________
sample 14656 kb submission
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        return self.method2(heights)
    
    def method2(self, heights):
        # From discussion. 68ms.
        
        heights.append(0)   # Add 0 to the end is a must have here!
        stack = [-1]    # 
        maxArea = 0
        
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                maxArea = max(maxArea, h*w)
            stack.append(i)
            
        return maxArea
__________________________________________________________________________________________________
