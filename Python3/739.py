__________________________________________________________________________________________________
sample 492 ms submission
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0]*len(T)
        i=len(T)-2
        cons = len(T)-1
        while i >= 0:
            q=i+1
            while True:
                if T[i]<T[q]:
                    res[i]=q-i
                    break
                else:
                    if res[q]==0:
                        res[i]=0
                        break
                    q+=res[q]
            i-=1
        return res
__________________________________________________________________________________________________
sample 16416 kb submission
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        result = [0] * n
        
        stack = [0]
        
        for i in range(1, n):
            while stack and T[stack[-1]] < T[i]:
                j = stack.pop()
                
                result[j] = i-j
            
            stack.append(i)
        
        return result
__________________________________________________________________________________________________
