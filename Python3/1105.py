__________________________________________________________________________________________________
sample 28 ms submission
class Shelf:
    def __init__(self, width, height):
        self.width = width
        self.height = height


class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        # min_heights[i] is the min total height of bookcase, ending with book[i]
        min_heights = [0] * (len(books) + 1)
        
        # O(n)
        # for each book, construct its min shelf
        for i in range(1, len(min_heights)):
            # max possible height is to put curr book on new shelf
            min_heights[i] = min_heights[i - 1] + books[i - 1][1]
            
            # track shelf total dimensions
            shelfw = books[i - 1][0]
            shelfh = books[i - 1][1]
            
            # try to backfill curr shelf with previous books
            # O(n)
            j = i - 1
            while j >= 1 and (shelfw + books[j - 1][0]) <= shelf_width:
                # add book width to shelf width
                shelfw += books[j - 1][0]
                
                # update height of shelf to be tallest book
                shelfh = max(shelfh, books[j - 1][1])
                
                min_heights[i] = min(min_heights[i], min_heights[j - 1] + shelfh)
                
                j -= 1
        return min_heights[-1]
"""
n = len(books)
time: O(n^2)
space: O(n)
"""                    
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        
        
        
        
        N, W = len(books), shelf_width
        dp = [float('inf')] * N             # dp[i] is the MIN height for books[:i+1]
        for i,(w,h) in enumerate(books):
            if i == 0:
                dp[i] = h
            else:
                dp[i] = dp[i-1] + h
                thick = w
                height = h
                for j in range(i-1, -1, -1):
                    if books[j][0] + thick > W:
                        break
                    thick += books[j][0]
                    height = max(books[j][1], height)
                    if j == 0:
                        if height < dp[i]:
                            dp[i] = height
                    elif j > 0:
                        if dp[j-1] + height < dp[i]:
                            dp[i] = dp[j-1] + height
        return dp[-1]
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def minHeightShelves(self, books: list, shelf_width: int) -> int:
        dp = [float('inf') for _ in range(len(books) + 1)]
        dp[0] = 0
        for i in range(1,len(dp)):
            max_width = shelf_width
            max_height = 0
            j = i - 1
            while j >= 0 and max_width >= books[j][0]:
                max_width -= books[j][0]
                max_height = max(max_height,books[j][1])
                dp[i] = min(dp[i],dp[j] + max_height)
                j -= 1

        return dp[-1]