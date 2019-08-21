__________________________________________________________________________________________________
sample 60 ms submission
import string


class Solution:
    """O(n) solution

    Think about string "XAXAXXAX" and focus on making the second "A" a unique
    character.
    We can take "XA(XAXX)AX" and between "()" is our substring. To make the
    second "A" counted as a uniq character, we need to:

    1. insert "(" somewhere between the first and second A
    2. insert ")" somewhere between the second and third A

    For step 1 we have "A(XA" and "AX(A", 2 possibility.
    For step 2 we have "A)XXA", "AX)XA" and "AXX)A", 3 possibilities.

    So there are in total 2 * 3 = 6 ways to make the second A a unique character
    in a substring.
    In other words, there are only 6 substring, in which this A contribute 1
    point as unique string.

    Instead of counting all unique characters and struggling with all possible
    substrings, we can count for every char in S, how many ways to be found as a
    unique char. We count and sum, and it will be the answer.
    """

    MODULO_BASE = 10 ** 9 + 7

    def uniqueLetterString(self, s: str) -> int:
        # index[c] stores the last two indexes of appearance of c.
        index = {c: [-1, -1] for c in string.ascii_uppercase}
        total = 0
        for i, c in enumerate(s):
            k, j = index[c]
            total += (i - j) * (j - k)
            index[c] = [j, i]
        # Calculate the last occurrence for each letter as well.
        for c in index:
            k, j = index[c]
            total += (len(s) - j) * (j - k)
        return total % self.MODULO_BASE
__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def uniqueLetterString(self, S: str) -> int:
        # https://leetcode.com/problems/unique-letter-string/discuss/128952/One-pass-O(N)-Straight-Forward
        # https://www.icode9.com/content-4-25511.html
        res = 0
        kMod = 1e9 + 7
        char_pos = collections.defaultdict(lambda : [-1, -1])
        for i, c in enumerate(S): # process all unique but last one
            k, j = char_pos[c]
            res += (j - k) * (i - j)
            char_pos[c] = [j, i]
        n = len(S)
        for  c in char_pos: # ATTN only process char_pos.keys(if you process S again,you will duplicate if some appear more than once) only process process last unique
            k, j = char_pos[c]
            res += (n - j) * (j - k)
        
        return int(res % kMod)
__________________________________________________________________________________________________
