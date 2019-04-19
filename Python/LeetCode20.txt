__________________________________________________________________________________________________
32ms
class Solution:
    def isValid(self, s: 'str') -> 'bool':
        v = []
        d = {']':'[', ')':'(', '}':'{'}
        for i in range(len(s)):
            if s[i] in d.values():
                v.append(s[i])
            elif s[i] in d.keys():
                if len(v) == 0:
                    return False
                elif v[-1] == d[s[i]]:
                    v.pop()
                else:
                    return False
        if v == []:
            return True
        else:
            return False
__________________________________________________________________________________________________
36ms
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        st = []
        for ch in s:
            if ch == '[':
                st.append(']')
            elif ch == '{':
                st.append('}')
            elif ch == '(':
                st.append(')')
            elif not st or st.pop()!=ch:
                return False
        return st == []
__________________________________________________________________________________________________
40ms
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        bra = ('(', ')')
        cur = ('{', '}')
        squ = ('[', ']')
        brackets = [bra, cur, squ]
        for char in s:
            for b in brackets:
                if char == b[0]:
                    stack.append(b[0])
                elif char == b[1]:
                    if len(stack) <= 0:
                        return False
                    last = stack.pop()
                    if not last == b[0]:
                        return False
        return len(stack) == 0
__________________________________________________________________________________________________
12128 kb
class Solution:
    def isValid(self, s: 'str') -> 'bool':
        dictt = {')': '(',
                ']' : '[',
                '}' : '{'}
        que = ''
        i = 0
        while i < len(s):
            if s[i] in dictt:
                if que == '':
                    return False
                elif que[-1] == dictt[s[i]]:
                    que = que[:-1]
                    i += 1
                else:
                    return False
            else:
                que += s[i]
                i += 1
        if que == '':
            return True
        return False
__________________________________________________________________________________________________
12136 kb
class Solution:
    def isValid(self, s: 'str') -> 'bool':
        dictt = {')': '(',
                ']' : '[',
                '}' : '{'}
        que = []
        i = 0
        while i < len(s):
            if s[i] in dictt:
                if que == []:
                    return False
                elif que[-1] == dictt[s[i]]:
                    que = que[:-1]
                    i += 1
                else:
                    return False
            else:
                que.append(s[i])
                i += 1
        if que == []:
            return True
        return False
__________________________________________________________________________________________________
