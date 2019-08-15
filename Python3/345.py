__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        l = len(s)
        p1 = 0
        p2 = l - 1
        f1 = f2 = False
        set_ = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'}
        while p1 < p2:
            if s[p1] in set_:
                while (p1 < p2):
                    if s[p2] in set_:
                        tem = s[p1]
                        s[p1] = s[p2]
                        s[p2] = tem
                        p1+=1
                        p2-=1
                        break
                    else:
                        p2 -= 1
            else:
                p1 += 1
        return ''.join(s)
__________________________________________________________________________________________________
sample 13768 kb submission
class Solution:
    def reverseVowels(self, s: str) -> str:
        
        ss = ['a','e','i','o','u','A','E','I','O','U']
        temp = []
        for i in s:
            if i in ss:
                temp.append(i)
        res = ''
        for i in s:
            if i in ss:
                
                res+=temp.pop()
            else:
                res+=i 

        return res
__________________________________________________________________________________________________
