__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def grayCode(self, n: int) -> List[int]:
        l = [0]
        for k in range(n):
            t = []
            f = 1
            for x in l:
                if f > 0:
                    t.append(x)
                    t.append(x + 2 ** k)
                else:
                    t.append(x + 2 ** k)
                    t.append(x)
                f = f * (-1)
            l = [p for p in t]
        return l
__________________________________________________________________________________________________
sample 13040 kb submission
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0]
        
        if (n == 0):
            return ans
        
        count = 0
        while (count < n):
            val = pow(2, count)
            cur_size = len(ans)
            for i in range(cur_size-1, -1, -1):
                ans.append(ans[i]+val)
            count += 1
        
        return ans        
__________________________________________________________________________________________________
