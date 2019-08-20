__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def countSubstrings(self, s: str) -> int:
        def manachers(s):
            A = '@#' + '#'.join(s) + '#$'
            Z = [0] * len(A)
            center = right = 0
            for i in range(1, len(A) - 1):
                if i < right:
                    Z[i] = min(right - i, Z[2 * center - i])
                while A[i + Z[i] + 1] == A[i - Z[i] - 1]:
                    Z[i] += 1
                if i + Z[i] > right:
                    center, right = i, i + Z[i]
            return Z

        return sum((v+1)//2 for v in manachers(s))
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def countSubstrings(self, s: str) -> int:
        countSubs = 0
        length = len(s)
        for index in range(length):
            countSubs += palindrome(s, index, index)
            countSubs += palindrome(s, index, index + 1)
        
        return countSubs

def palindrome(string: str, s, e) -> int:
        length = len(string)
        count = 0
        while (s >= 0 and e < length and string[s] == string[e]):
            s -= 1
            e += 1
            count += 1
        return count
__________________________________________________________________________________________________
