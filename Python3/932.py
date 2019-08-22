__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def beautifulArray(self, N: int, memo = {1:[1]}) -> List[int]:
        if N not in memo:
            odd_project = self.beautifulArray((N+1)//2, memo)
            even_project = self.beautifulArray(N//2, memo)
            memo[N] = [2*x-1 for x in odd_project] + [2*x for x in even_project]
        return memo[N]        
__________________________________________________________________________________________________
sample 12980 kb submission
class Solution:
    def ba(self, l: List[int]) -> List[int]:
        if len(l) <= 2:
            return l
        return self.ba(l[0::2]) + self.ba(l[1::2])
    def beautifulArray(self, N: int) -> List[int]:
        return self.ba([i + 1 for i in range(N)])
__________________________________________________________________________________________________
