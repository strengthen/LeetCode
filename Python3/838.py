__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        res = ''
        count = 0
        for d in dominoes:
            if d == '.':
                count += 1
            elif not res or res[-1] == 'L':
                if d == 'L':
                    res += 'L' * (count + 1)
                else:
                    res += '.' * count + 'R'
                count = 0
            else:
                if d == 'R':
                    res += 'R' * (count + 1)
                else:
                    res += ('R' * (count // 2) 
                            + ('.' if count & 1 else '')
                            + 'L' * (count // 2 + 1))
                count = 0
        if count > 0:
            if not res or res[-1] == 'L':
                res += '.' * count
            elif res[-1] == 'R':
                res += 'R' * count
        return res
__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        ans, cnt, toRight = '', 0, False
        for c in dominoes:
            if c == 'L':
                if toRight:
                    ans += 'R'*(cnt//2) + '.'*(cnt-cnt//2*2) + 'L'*(cnt//2+1)
                else:
                    ans += 'L'*(cnt+1)
                cnt, toRight = 0, False
            elif c == 'R':
                if toRight:
                    ans += 'R'*(cnt+1)
                else:
                    ans += '.'*cnt + 'R'
                cnt, toRight = 0, True
            else:
                cnt += 1
        if cnt > 0:
            if toRight:
                ans += 'R'*cnt
            else:
                ans += '.'*cnt
        return ans
__________________________________________________________________________________________________
