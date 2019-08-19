__________________________________________________________________________________________________
sample 336 ms submission
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        valid_components = set(words)
        result = []
        
        memo = {"": True}
        def helper(word):
            if word in memo:
                return memo[word]
            
            memo[word] = False
            for i in range(1, len(word) + 1):
                if word[:i] in valid_components and helper(word[i:]):
				    # update the set along checking
                    #valid_components.add(word)
                    memo[word] = True
                    return True
            
            return False
        
        for word in words:
		    # this range avoids checking the whole word in the valid set
            for i in range(1, len(word)):
                if word[:i] in valid_components and helper(word[i:]):
                    result.append(word)
                    break
                    
        return result
__________________________________________________________________________________________________
sample 15940 kb submission
class Solution:
    def findAllConcatenatedWordsInADict(self, A: List[str]) -> List[str]:
        S = set(A)
        ans = []
        for word in A:
          if not word: continue
          stack = [0]
          seen = {0}
          M = len(word)
          while stack:
            node = stack.pop()
            if node == M:
              ans.append(word)
              break
            for j in range(M - node + 1):
              if (word[node:node+j] in S and 
                  node + j not in seen and
                  (node > 0 or node + j != M)):
                stack.append(node + j)
                seen.add(node + j)

        return ans
__________________________________________________________________________________________________
