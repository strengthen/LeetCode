__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        ans = []
        X = sum(shifts) % 26
        for i, c in enumerate(S):
            index = ord(c) - ord('a')
            ans.append(chr(ord('a') + (index + X) % 26))
            X = (X - shifts[i]) % 26

        return "".join(ans)
__________________________________________________________________________________________________
sample 15224 kb submission
class Solution:
    def shiftingLetters(self, S: str, shifts: List[int]) -> str:
        tot_shift, S = 0, list(S)
        for i, shift, char in zip(range(len(S) - 1, -1, -1),
                                    reversed(shifts), reversed(S)):
            tot_shift += shift
            char = ord(char) - ord('a')
            char = (char + tot_shift) % 26
            S[i] = chr(char + ord('a'))
        return "".join(S)
__________________________________________________________________________________________________
