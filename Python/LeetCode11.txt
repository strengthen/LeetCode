__________________________________________________________________________________________________
48ms
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = area = 0
        left, right = 0, len(height) - 1
        while left < right:
            l, r = height[left], height[right]
            if l < r:
                area = (right - left) * l
                #print(str(area)+"area")
                while height[left] <= l: #Iterate till u find a better left. i.e higher than l.
                    left += 1
                    #print("left:"+str(left))
            else:
                area = (right - left) * r
                #print("area"+str(area)+"area")
                while height[right] <= r and right:
                    right -= 1
                    #print("right:"+str(right)+" "+str(height[right])+" "+str(r) )
            if area > max_area:
                max_area = area
        return max_area
    
        """ slower code"""
        max_A = 0
        l = 0
        r = len(height) - 1
        while l < r:
            max_A = max(max_A, min(height[r],height[l])*(r-l)) 
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return max_A
__________________________________________________________________________________________________
52ms
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left, right = 0, len(height) - 1
        
        while left < right:
            l, r = height[left], height[right]
            if l < r:
                area = (right - left) * l
                while height[left] <= l: 
                    left += 1
            else:
                area = (right - left) * r
                while height[right] <= r and right:
                    right -= 1
            if area > max_area:
                max_area = area
        return max_area
__________________________________________________________________________________________________
56ms
class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l, r = iter(height), iter(height[::-1])
        hl, hr = next(l), next(r)
        for d in range(len(height) - 1, 0, -1):
            if hl < hr:
                ans = max(ans, hl * d)
                hl = next(l)
            else:
                ans = max(ans, hr * d)
                hr = next(r)
        return ans            
__________________________________________________________________________________________________
13280 kb 
class Solution:
    def maxArea(self, height: 'List[int]') -> 'int':
        arr_len = len(height)
        area = 0
        front = 0
        rear = arr_len - 1
        while front < rear:
            if height[front] < height[rear]:
                h = height[front]
                front += 1
            else:
                h = height[rear]
                rear -= 1
            new_area = h * (arr_len - 1)
            area = max(area, new_area)
            arr_len -= 1
        return area
__________________________________________________________________________________________________
13308 kb
class Solution:
    def maxArea(self, height: 'List[int]') -> 'int':
        max_num=0
        for i in range(len(height)):
            max_num = max(min(height[0], height[-1])*(len(height)-1), max_num)
            if len(height)>2:
                if height[0]>=height[-1]:
                    del height[-1]
                else:
                    del height[0]
            else:
                return max_num
__________________________________________________________________________________________________
