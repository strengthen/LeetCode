__________________________________________________________________________________________________
sample 16 ms submission
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        out_list = []
        x = 1
        while x<1000:
            y = 1
            if customfunction.f(x, y) > z:
                break
            while y<1000:
                if customfunction.f(x, y) > z:
                    break
                if customfunction.f(x, y) == z:
                    out_list.append([x,y])
                y+=1
            x+=1
        return out_list
__________________________________________________________________________________________________
sample 20 ms submission
"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        def f(x, y):
            return customfunction.f(x, y)
            
        def find_sol(y, x_L, x_R):
            while x_L<=x_R:
                mid = x_L+(x_R-x_L)//2
                f_mid = f(mid, y)
                if(f_mid == z):
                    return [mid, y]
                elif(f_mid < z):
                    x_L = mid+1
                else:
                    x_R = mid-1
            return []
            
        #print (f(1, 1), f(4, 1))
        #return
    
        if(f(1, 1)>z):
            return []
        elif(f(1, 1)==z):
            return [[1, 1]]
        x_R = 1
        while(f(x_R, 1)<z):
            x_R *= 2
        sol = []
        y = 1
        while x_R>=1 and f(1, y)<=z:
            #print (y, x_R)
            tmp = find_sol(y, 1, x_R)
            if(tmp):
                sol.append(tmp)
            y += 1
            if(tmp):
                x_R = tmp[0]-1
        return sol
__________________________________________________________________________________________________
