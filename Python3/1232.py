__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n=len(coordinates)
        if n<=2:
            return True
        x0, y0 = coordinates[0]
        x1, y1 = coordinates[1]
        slope=(x1-x0)*y0-(y1-y0)*x0
        for x,y in coordinates:
            if (x1-x0)*y-(y1-y0)*x!=slope:
                return False
        return True
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        
        for i in range(2,len(coordinates)):
            
            if int(coordinates[i-1][0] - coordinates[i-2][0]) == 0:
                return False
            else: 
                m1 = (coordinates[i-1][1] - coordinates[i-2][1]) / (coordinates[i-1][0] - coordinates[i-2][0])
            
            if int(coordinates[i][0] - coordinates[i-1][0]) == 0:
                return False
            else: 
                m2 = (coordinates[i][1] - coordinates[i-1][1]) / (coordinates[i][0] - coordinates[i-1][0])
            
            if m1 != m2:
                return False
            
            return True
__________________________________________________________________________________________________
