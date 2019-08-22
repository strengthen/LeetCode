__________________________________________________________________________________________________
sample 884 ms submission
class Solution:
    def minKBitFlips(self, a: List[int], k: int) -> int:
        n = len(a)
        first_zero = -1
        looking_for = 0
        index = -1
        switch = -1
        count = 0
        switches = [0]*(n+1)
        prev_s = 0
        for i in range(n):
            if 1==switches[i]:
                looking_for = 1-looking_for
            #print(count)
            #print("i is "+str(i)+'i am looking for '+str(looking_for))
            if a[i]==looking_for:
                if n-i<k:
                    return -1
                else:
                    looking_for = 1-looking_for
                    switches[i+k] = 1
                    count+=1
        return count   
__________________________________________________________________________________________________
sample 13824 kb submission
from collections import deque
class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        flipped = deque()
        curr = 0
        ans = 0
        for i, x in enumerate(A):
            if i >= K:
                curr ^= flipped[0] 
            if curr^A[i] != 1: 
                if len(A) - i < K: return -1
                ans += 1
                curr ^= 1
                flipped.append(1)
            else:
                flipped.append(0)
            if len(flipped) > K:
                flipped.popleft()
        return ans
__________________________________________________________________________________________________
