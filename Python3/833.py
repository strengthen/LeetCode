__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
  def findReplaceString(self, S, indexes, sources, targets):
    S = list(S)
    for i, src, tgt in sorted(zip(indexes, sources, targets), reverse=True):
      if S[i:i+len(src)] == list(src):
        S[i:i+len(src)] = list(tgt)
    return "".join(S)    
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        """
        [a, b, ffff, ""]
        """
        arr = [c for c in S]
        
        for i, src, tgt in zip(indexes, sources, targets):
            if S[i:i+len(src)] == src:
                arr[i] = tgt
                for j in range(i+1, i+len(src)):
                    arr[j] = ""
        return "".join(arr)
__________________________________________________________________________________________________
