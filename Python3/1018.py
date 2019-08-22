__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        res = [False] * len(A)
        cur = 0
        for i in range(len(A)):
            cur = (2 * cur + A[i]) % 5
            if not cur:
                res[i] = True
        return res
__________________________________________________________________________________________________
sample 15972 kb submission
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        if not A:
            return []
        result = []
        # A = [str(x) for x in A]
        memory = []
        memory.append(A[0])
        result.append(memory[0] == 0)
        for i in range(1, len(A)):
            memory.append((memory[i-1]*2 + A[i]) % 5)
            result.append(memory[i] == 0)
        # print(memory)
        return result
__________________________________________________________________________________________________
