__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        n = len(text)
        d = collections.defaultdict(collections.deque)
        # record index
        for i,v in enumerate(text):
            d[ord(v)-ord('a')].append(i)
        
        # search orderly
        keys = sorted(d.keys())
        res = []
        c = len(d)
        last_index = -1
        
        while len(res)<c:
            for i in range(len(keys)):
                #for the current key i, if this is less than all the other keys last one, then append this
                if all(d[keys[i]][0] < d[keys[j]][-1] for j in range(i+1, len(keys))):
                    res.append(chr(ord('a')+keys[i]))
                    last_index = d[keys[i]][0]
                    keys.remove(keys[i])
                    break
            # O(n) time, delete all index less than last_index
            for i in range(len(keys)):
                while d[keys[i]] and d[keys[i]][0] < last_index:
                    d[keys[i]].popleft()
        return ''.join(res)
__________________________________________________________________________________________________
sample 24 ms submission
class Solution(object):
    def smallestSubsequence(self, text):
        """
        :type text: str
        :rtype: str
        """
        last_idx = dict()
        for pos, char in enumerate(text): # O(n)
            last_idx[char] = pos
            
        stack = []
        for pos, char in enumerate(text): # O(n^2)
            if char in stack:
                continue
            while stack and char < stack[-1] and last_idx[stack[-1]] > pos:
                stack.pop()
            stack.append(char)
        return ''.join(stack)
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def smallestSubsequence(self, s):
        last={char:i for i,char in enumerate(s)}
        ans=''
        for i,char in enumerate(s):
            if char not in ans:
                while char<ans[-1:] and last[ans[-1:]]>i:
                    ans=ans[:-1]
                ans+=char
        return ans