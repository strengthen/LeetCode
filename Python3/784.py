__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        groups = [[e] if "0" <= e <= "9" else [e.lower(), e.upper()] for e in S]
        return ["".join(e) for e in itertools.product(*groups)]
__________________________________________________________________________________________________
sample 13572 kb submission
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
      res = []
      letter = ''
      for char in S:
        if not char.isdigit():
          letter = char
          break
      if letter == '':
        return [S]
      string = S.partition(letter)
      perms = self.letterCasePermutation(string[2])
      for perm in perms:
        upper = string[0] + letter.upper() + perm
        res.append(upper)
        lower = string[0] + letter.lower() + perm
        res.append(lower)
      return res
__________________________________________________________________________________________________
