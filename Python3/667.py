__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:        
        ans = list(range(1,n-k+1))       
        for i in range(1,k+1):            
            if i % 2 == 1:
                ans.append(n-i // 2)
            else:
                ans.append(n-k+ i // 2)
        return ans
__________________________________________________________________________________________________
sample 13976 kb submission
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = [0] * n
        cnt = 1
        for i in range(0, k + 1, 2):
            ans[i] = cnt
            cnt += 1
        cnt = k + 1
        for i in range(1, k + 1, 2):
            ans[i] = cnt
            cnt -= 1
        for i in range(k + 1, n):
            ans[i] = i + 1
        return ans
__________________________________________________________________________________________________
