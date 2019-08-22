__________________________________________________________________________________________________
sample 336 ms submission
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if not A:
            return 0
        unique = set() # unique values
        non_unique = []
        res = 0
        for a in A:
            if a in unique:
                non_unique.append(a)
            else:
                unique.add(a)
                
        # now change non-uniuque values to unique values
        non_unique.sort()
        cur = min(A)
        for a in non_unique:
            while cur in unique or cur < a:
                cur += 1
            # change a to cur
            unique.add(cur)
            res += cur-a
            cur += 1
            
        return res
__________________________________________________________________________________________________
sample 16996 kb submission
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        n = len(A)
        if n <= 1:
            return 0
        A.sort()
        count = 0
        for i in range(n-1):
            if (A[i] >= A[i+1]):
                diff = A[i] - A[i+1]
                A[i+1]+=(diff+1)
                count +=(diff+1)
        return count
__________________________________________________________________________________________________
