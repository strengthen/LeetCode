__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        nav = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        row, col = len(image), len(image[0])
        color = image[sr][sc]
        if newColor == color: return image
        def dfs(image, i, j):
            image[i][j] = newColor
            for x, y in nav:
                r, c = i + x, j + y
                if r >= row or r < 0 or c < 0 or c >= col or image[r][c] != color:
                    continue
                dfs(image, r, c)
                
        dfs(image, sr, sc)
            
        return image
__________________________________________________________________________________________________
sample 13172 kb submission
class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if (image[sr][sc]==newColor):
            return image
        
        
        def adjacent_flood(sr,sc):
            adjacent  = (sr-1,sc),(sr+1,sc),(sr,sc-1),(sr,sc+1)
            for x,y in adjacent:
                if (x>=0) and (x<len(image)) and (y >=0) and (y<len(image[0]))and (image[x][y]== color):
                    image[x][y]= newColor
                    adjacent_flood(x,y)
        
        color = image[sr][sc]
        image[sr][sc] = newColor
        adjacent_flood(sr,sc)
        return image        
__________________________________________________________________________________________________
