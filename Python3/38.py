__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def countAndSay(self, n: int) -> str:
        if n <= 0:
            return "" 
        if n == 1:
            return "1"
        m = self.countAndSay(n-1)
        ans = ""
        c = m[0]

        count = 0
        for i in range(0, len(m)):
            if m[i] == c:
                count += 1
            else:
                ans += str(count)
                ans += c
                c = m[i]
                count = 1
        ans += str(count)
        ans += c
        return ans
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def countAndSay(self, n: 'int') -> 'str':        
        next_str = '1'
        new_str = ''
        for num in range(1, n):
            count = 1
            index = 0
            while index < len(next_str)-1:
                if next_str[index+1] == next_str[index]:
                    count+=1
                else:
                    new_str += str(count) + next_str[index]
                    count=1
                index += 1
            new_str += str(count) + next_str[index]
            next_str = new_str
            new_str = ''
        return next_str
__________________________________________________________________________________________________
