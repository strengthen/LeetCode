__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        hash_1=0
        hash_2=0
        d=len(s1)
        for i in range(d):
            hash_1+=hash(s1[i])
            hash_2+=hash(s2[i])
        if hash_1==hash_2:
            return True
        for i in range(d,len(s2)):
            hash_2+=hash(s2[i])-hash(s2[i-d])
            if hash_1==hash_2:
                return True
        return False
__________________________________________________________________________________________________
sample 13096 kb submission
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        from collections import Counter
        counter = Counter(s1)
        res = p1 = p2 = 0
        
        while p2 < len(s2):
            if s2[p2] not in counter:
                while p1 < p2:
                    counter[s2[p1]] += 1
                    if counter[s2[p1]] == 1:
                        res -= 1
                    p1 += 1
                p1 = p2 + 1
            else:
                counter[s2[p2]] -= 1
                if counter[s2[p2]] == 0:
                    res += 1
                if res == len(counter):
                    return True
                if counter[s2[p2]] == -1:
                    while 1:
                        counter[s2[p1]] += 1
                        if counter[s2[p1]] == 1:
                            res -= 1
                        if s2[p1] == s2[p2]:
                            p1 += 1
                            break
                        p1 += 1
            p2 += 1
        
        return False
__________________________________________________________________________________________________
