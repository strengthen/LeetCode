__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        N = 0
        for i, c in enumerate(S):
            N = N * int(c) if c.isdigit() else N + 1
            if K <= N: break
        for j in range(i, -1, -1):
            c = S[j]
            if c.isdigit():
                N /= int(c)
                K %= N
            else:
                if K == N or K == 0: return c
                N -= 1
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        stack, l = [], 0
        for c in S:
            l = l + 1 if c.isalpha() else l * int(c)
            stack += c,
            while l >= K:
                while stack[-1].isdigit(): l //= int(stack.pop())
                K = K % l
                if not K: return stack[-1]
                l -= 1
                stack.pop()        
__________________________________________________________________________________________________
