__________________________________________________________________________________________________
44ms
class Solution:
    def isMatch(self, s, p):
        
        if not p and not s: return True
        len_p, len_s = len(p), len(s)
        s = '!' + s
        matches = {}

        def matching(i,j,star,star_value):
            if j == -1: return i == 0
            out = False
            if (i,j) not in matches:
                if not star:
                    while p[j] == s[i] or (i != 0 and p[j] == '.'):
                        i-=1 
                        j-=1
                        if j == -1: return i == 0

                    if p[j] == '*': 
                        if i == 0: out = matching(i,j-1,True,'?')
                        else: out = matching(i,j-1,True,p[j-1])
                    else: out = False

                else:
                    if s[i] == star_value or (p[j] == '.' and i != 0):
                        out = out or matching(i-1,j,True,star_value) or matching(i,j-1,False,0)
                    else: out = out or matching(i,j-1,False,0)
                matches[(i,j)] = out
            return out


        return matching(len_s,len_p-1,False,0)
__________________________________________________________________________________________________
48ms
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        def dp(i, j):
            if (i, j) in memo: return memo[(i, j)]
            if j == len(p): 
                rlt = (i == len(s))
            else:
                match = i < len(s) and (p[j] in {s[i], '.'})
                if len(p) > j + 1 and (p[j + 1] == '*'):
                    rlt = dp(i, j + 2) or (match and dp(i + 1, j))
                else:
                    rlt = match and dp(i + 1, j + 1)
            
            memo[(i, j)] = rlt
            return memo[(i, j)]
            
        return dp(0, 0)
    
__________________________________________________________________________________________________
52ms
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        mem={}
        def helper(s,p):
            if (s,p) not in mem:
                if not p:
                    mem[(s,p)]=not bool(s)
                else:
                    first_match = bool(s) and p[0] in {s[0], '.'}
                    if len(p) >= 2 and p[1] == '*':
                        mem[(s,p)]= (helper(s, p[2:]) or
                                first_match and helper(s[1:], p))
                    else:
                        mem[(s,p)]= first_match and helper(s[1:], p[1:])
            return mem[(s,p)]
        return helper(s,p)
__________________________________________________________________________________________________
12152 kb
class Solution:
    def isMatch(self, s: 'str', p: 'str') -> 'bool':
        text = s
        pattern = p
        dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

        dp[-1][-1] = True
        for i in range(len(text), -1, -1):
            for j in range(len(pattern) - 1, -1, -1):
                first_match = i < len(text) and pattern[j] in {text[i], '.'}
                if j+1 < len(pattern) and pattern[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]

        return dp[0][0]
        
__________________________________________________________________________________________________
12252 kb
class Solution(object):
    def isMatch(self, s, p):
        r = len(s)+1
        c = len(p)+1
        res = [[False for j in range(c)] for i in range(r)]
        res[0][0] = True
        # For filling the first row and handling a* or a*b*.Such patterns can match empty string
        for j in range(1,c):
            if p[j-1] == "*": 
                res[0][j] = res[0][j-2]
        
        # For filling the Dp array
        for i in range(1,r):
            for j in range(1,c):
                # If the characters match or pattern has . then check if string and pattern without i and j match
                if s[i-1] == p[j-1] or p[j-1] == ".":
                    res[i][j] = res[i-1][j-1]
                    
                # If pattern contains * check if string char matches char before * or zero occurences of char before *
                elif p[j-1] == "*":
                    if res[i][j-2]:
                        res[i][j] = res[i][j-2]
                    elif s[i-1] == p[j-2] or p[j-2]==".":
                        res[i][j] = res[i-1][j]
        return res[r-1][c-1]
__________________________________________________________________________________________________
