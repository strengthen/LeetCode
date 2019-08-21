__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        def count(A):
            ans = [0] * 52
            for i, letter in enumerate(A):
                ans[ord(letter) - ord('a') + 26 * (i%2)] += 1
            return tuple(ans)
        return len({count(word) for word in A})
__________________________________________________________________________________________________
sample 13208 kb submission
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        temp = ["".join(sorted(a[::2]) + sorted(a[1::2])) for a in A]
        # print(temp)
        return len(list(set(temp)))
__________________________________________________________________________________________________
