__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = set()
        def find(s, cb):
            if cb and len(cb)==4:
                if not s:
                    res.add('.'.join(cb))
                return
            if not s:
                return
            find(s[1:], cb+[s[:1]])
            if s[0]=='0':
                return
            n = len(s)
            if n>=2:
                find(s[2:], cb+[s[:2]])
            if n>=3:
                val = int(s[:3])
                if val<=255:
                    find(s[3:], cb+[s[:3]])
        find(s, [])
        return list(res)
__________________________________________________________________________________________________
sample 12968 kb submission
class Solution:
    # @param s: str
    # @return List[str]
    def restoreIpAddresses(self, s):
        results = []
        self.dfs(results, s, "", 0, 1)
        return results
    
    def dfs(self, results, s, path, start, section):
        if section == 4:
            segment = s[start:]
            if self.isValid(segment):
                results.append(path + segment)
            return None
        elif section > 4:
            return None
        for i in range(start, start + 3):
            segment = s[start:i + 1]
            if self.isValid(segment):
                self.dfs(results, s, path + segment + ".", i + 1, section + 1)
        return None
    
    # @param s: str
    # @return bool
    def isValid(self, s):
        if len(s) > 3 or len(s) == 0:
            return False
        
        if len(s) == 1 and s[0] == "0":
            return True
        elif s[0] == "0":
            return False
        
        return 0 < int(s) <= 255
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def dfs(i, path):
            nonlocal ans
            if len(path) >= 4 and i < len(s): return
            if i >= len(s):
                if len(path) == 4:
                    ans.append('.'.join(path))
                return
            
            for j in range(i + 1, min(len(s) + 1, i + 4)):
                k = int(s[i: j])
                if s[i] == '0' and j > i + 1: continue
                if 0 <= k <= 255:
                    dfs(j, path + [str(k)])
                    
        ans = []
        dfs(0, [])
        return ans