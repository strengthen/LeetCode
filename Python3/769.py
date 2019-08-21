__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack=[]
        minMax=[arr[0],arr[0]]
        stack.append(minMax)
        def helper(op1:List[int],op2:List[int]):
            ret=[0,0]
            ret[0]=min(op1[0],op2[0])
            ret[1]=max(op1[1],op2[1])
            return ret
        for integer in arr[1:]:
            t=[integer,integer]
            while len(stack)>0:
                minMax=stack[-1]
                if t[0]<minMax[1]:
                    minMax=stack.pop()
                    t=helper(minMax,t)
                elif t[0]>=minMax[1]:
                    stack.append(t)
                    break
            else:
                stack.append(t)
        return len(stack)
__________________________________________________________________________________________________
sample 13064 kb submission
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        
        res=0
        max_n=-1
        for i,n in enumerate(arr):
            max_n=max(n,max_n)
            if i==max_n:
                res+=1
        
        return res
__________________________________________________________________________________________________
