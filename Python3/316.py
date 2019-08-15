__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        last_index = {}
        for index, ch in enumerate(s):
            last_index[ch] = index 
        cur_result = []
        for i, ch in enumerate(s):
            if ch not in cur_result:
                while cur_result and ch < cur_result[-1] and i < last_index[cur_result[-1]]:
                    cur_result.pop()
                cur_result.append(ch)
        return ''.join(cur_result)
__________________________________________________________________________________________________
sample 13128 kb submission
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter = collections.Counter(s)
        stk = []
        for a in s:
            if a not in stk:
                while stk and stk[-1] >= a and stk[-1] in counter:
                    # counter[stk[-1]]-=1
                    stk.pop()
                stk.append(a)
            counter[a]-=1
            if counter[a] <= 0:
                    del counter[a]

        return ''.join(stk)
__________________________________________________________________________________________________
