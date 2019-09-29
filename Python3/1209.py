__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        
        for i in s:
            if not stack:
                stack.append([i, 1])
            else:
                if stack[-1][0] == i:
                    stack[-1][-1] += 1
                    if stack[-1][-1] == k:
                        stack.pop()
                else:
                    stack.append([i, 1])
                    
        return ''.join(a * b for a, b in stack)
__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        pieces = [(char, len(list(group))) for char, group in itertools.groupby(s)]
        if all(length < k for _, length in pieces):
            return s
        return self.removeDuplicates(''.join(char * (length % k) for char, length in pieces), k)
__________________________________________________________________________________________________
