__________________________________________________________________________________________________
class Solution(object):
    def smallestSubsequence(self, text):
        """
        :type text: str
        :rtype: str
        """
        last_idx = dict()
        for i, c in enumerate(text):
            last_idx[c] = i
        stack = []
        for i, c in enumerate(text):
            if c in stack:
                continue
            while stack and c < stack[-1] and last_idx[stack[-1]] > i:
                stack.pop()
            stack.append(c)
        return ''.join(stack)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
