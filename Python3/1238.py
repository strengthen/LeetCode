__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        def helper(i):
            if i == 1:
                return [0, 1]
            temp = helper(i - 1)
            power = 2 ** (i - 1)
            return temp + [power + t for t in temp[::-1]]
        
        arr = helper(n)
        index = arr.index(start)
        return arr[index:] + arr[:index]
__________________________________________________________________________________________________
sample 184 ms submission
class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        if n==0:
            return [0]
        if n==1:
            return [0,1] if start==0 else [1,0]
        res=[0,1]
        for i in range(1,n):
            temp=[(1<<i) + each for each in res[::-1]]
            res=res + temp
        s=res.index(start)
        return res[s:]+res[:s]
__________________________________________________________________________________________________
