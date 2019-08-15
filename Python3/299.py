__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    #import operator
    
    def getHint(self, secret: str, guess: str) -> str:
        from collections import Counter
        bull = sum(map(operator.eq, secret, guess))
        a = Counter(secret)
        b = Counter(guess)
        cow = sum((a&b).values()) - bull
        return '{}A{}B'.format(bull,cow)
__________________________________________________________________________________________________
sample 12980 kb submission
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        w = []
        actual = []
        
        l = min(len(secret),len(guess))
        
        for i in range(l):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                w.append(guess[i])
                actual.append(secret[i])
        
        if len(guess) > l:
            for i in range(l,len(guess)):
                w.append(guess[i])
        
        if len(secret) > l:
            for i in range(l,len(secret)):
                actual.append(secret[i])
                
        cows = 0
        for x in w:
            if x in actual:
                cows += 1
                actual.remove(x)
        
        return "{bulls}A{cows}B".format(bulls=bulls,cows=cows)
__________________________________________________________________________________________________
