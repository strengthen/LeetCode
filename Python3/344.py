__________________________________________________________________________________________________
sample 200 ms submission
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s = s.reverse()
__________________________________________________________________________________________________
sample 17192 kb submission
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        head = 0
        tail = len(s) - 1
        while head < tail:
            s[head], s[tail] = s[tail], s[head]
            head += 1
            tail -= 1
        print(s)
__________________________________________________________________________________________________
