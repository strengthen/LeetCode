__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def maxScoreWords(self, words, letters, score):
        count = [0] * 27
        for letter in map(ord, letters):
            count[letter - 97] += 1
        
        ret = 0
        comb = [count]
        for word in words:
            for i in range(len(comb)):
                count = comb[i][:]
                for letter in map(ord, word):
                    index = letter - 97
                    if count[index] == 0:
                        break
                    count[index] -= 1
                    count[-1] += score[index]
                else:
                    comb.append(count)
                    if count[-1] > ret:
                        ret = count[-1]
        
        return ret
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        lets = collections.Counter(letters)
        wdMap = {}
        for wd in words:
            if wd not in wdMap:
                wdF = collections.Counter(wd)
                val = 0
                for c in wdF:
                    val += score[ord(c)-ord('a')]*wdF[c]
                wdMap[wd] = (val, wdF)
        self.res = 0
        n = len(words)
        
        def helper(i, available, ans):
            if i == n:
                if ans > self.res:
                    self.res = ans
                return
            wd = words[i]
            val, wdF = wdMap[wd]
            flag = True
            for c in wdF:
                if available[c] < wdF[c]:
                    flag = False
                    break
            if flag:
                for c in wdF:
                    available[c] -= wdF[c]
                helper(i+1, available, ans+val)
                for c in wdF:
                    available[c] += wdF[c]
            helper(i+1, available, ans)
        helper(0, lets, 0)
        return self.res
__________________________________________________________________________________________________
