__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def validPalindrome(self, s: str) -> bool:
        
        s_palindrome = s[::-1]
        
        if s == s_palindrome:
            return True
        
        c = len(s)
        
        for index_character in range(c):
            if s[index_character] != s_palindrome[index_character]:
                if index_character == c - 1:
                    return s[:index_character] == s[:index_character][::-1] or s_palindrome[:index_character] == s_palindrome[:index_character][::-1]
                else:
                    new_s = s[:index_character] + s[index_character + 1:]
                    new_s_palindrome = s_palindrome[:index_character] + s_palindrome[index_character + 1:]
                    return new_s == new_s[::-1] or new_s_palindrome == new_s_palindrome[::-1]
        return False
__________________________________________________________________________________________________
sample 13188 kb submission
class Solution:
    
    def validPalindrome(self, s: str) -> bool:
        allow = True
        i = 0
        j = len(s) - 1
        first_try = True
        
        while i < j:
            if s[i] != s[j]:
                if not allow:
                    first_try = False
                    break
                allow = False
                
                if s[i + 1] == s[j]:
                    i += 1
                elif s[i] == s[j - 1]:
                    j -= 1
                else:
                    first_try = False
                
            i += 1
            j -= 1
        
        
        if first_try == True:
            return True
        
        allow = True
        i = 0
        j = len(s) - 1
        
        while i < j:
            if s[i] != s[j]:
                if not allow:
                    return False
                allow = False
                
                if s[i] == s[j-1]:
                    j -= 1
                elif s[i+1] == s[j]:
                    i += 1
                else:
                    return False
                
            i += 1
            j -= 1
        
        return True
__________________________________________________________________________________________________
