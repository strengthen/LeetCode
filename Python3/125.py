__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isPalindrome(self, s: str) -> bool:
        ignore_chars = ',./<>?;\':"[]\{}|`~!@#$%^&*()-=_+ '
        for char in ignore_chars:
            if char in s:
                s = s.replace(char,'')
        return s.lower() == s.lower()[::-1]    
__________________________________________________________________________________________________
sample 13024 kb submission
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        l, r = 0, len(s) - 1
        while (l < r): 
            if s[l].isalnum() and s[r].isalnum():
                if s[l] != s[r]:
                    return False
                else:
                    l += 1
                    r -= 1
            elif s[l].isalnum():
                r -= 1
            elif not s[l].isalnum():
                l += 1
            
        return True
__________________________________________________________________________________________________
