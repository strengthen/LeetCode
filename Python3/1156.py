__________________________________________________________________________________________________
class Solution:
    def maxRepOpt1(self, s: str) -> int:
        res = 0
        count = collections.Counter()
        countChar = collections.Counter(s)
        start = 0
        maxCount = 0
        maxChar = s[0]
        
        for right in range(len(s)):
            count[s[right]] += 1
            maxCount = max(count[s[right]],maxCount)

            while right-start+1 - maxCount > 1:
                count[s[start]] -= 1
                start += 1
            maxChar = max(count.items(),key=lambda x: x[1])[0]
            if right-start +1 > res:
                res = right-start+1
        return min(res,countChar[maxChar])
__________________________________________________________________________________________________

__________________________________________________________________________________________________
