__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        missing_type = 3
        if any('a' <= c <= 'z' for c in s): missing_type -= 1
        if any('A' <= c <= 'Z' for c in s): missing_type -= 1
        if any(c.isdigit() for c in s): missing_type -= 1

        change = 0
        one = two = 0
        p = 2
        while p < len(s):
            if s[p] == s[p-1] == s[p-2]:
                length = 2
                while p < len(s) and s[p] == s[p-1]:
                    length += 1
                    p += 1
                    
                change += length // 3
                if length % 3 == 0: one += 1
                elif length % 3 == 1: two += 1
            else:
                p += 1
        
        if len(s) < 6:
            return max(missing_type, 6 - len(s))
        elif len(s) <= 20:
            return max(missing_type, change)
        else:
            delete = len(s) - 20
            
            change -= min(delete, one)
            change -= min(max(delete - one, 0), two * 2) // 2
            change -= max(delete - one - 2 * two, 0) // 3
                
            return delete + max(missing_type, change)
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        pass_length = len(s)
        corrections = 0
        Upper = False
        lower = False
        digit = False   
        rep_ind = []
        i = 0
        #print(pass_length)
        if pass_length < 4:
            return 6-pass_length
        while i < len(s):
            if s[i].isdigit():
                digit = True;
            elif s[i].isupper():
                Upper = True;              
            elif s[i].islower():
                lower = True
                
            if i< len(s) - 1 and s[i] == s[i+1]:
                ind = i 
                rep  = 1
                i+=1
                while i< len(s) and s[i] == s[i-1]:
                    i+=1
                    rep+=1
                if pass_length > 20 and rep%3 == 0:
                    pass_length -= 1
                    rep -=1
                    corrections+=1
                if rep >2:
                    rep_ind.append(rep)
                
            else:
                i+=1
        #rep_ind.sort()
        #print(pass_length)
        num_replace = 3
        if digit:
            num_replace -=1
        if Upper:
            num_replace -=1
        if lower:
            num_replace -=1
        if pass_length < 6:
            return max(6-pass_length, num_replace)
        elif pass_length < 21:
            num_rp = 0
            for c in rep_ind:
                num_rp += c//3
            return corrections+ max(num_rp,num_replace)
        else:
            #print(rep_ind)
            num_del = max(0, pass_length-20)
            num_rp = 0
            ri = 0
            while ri < len(rep_ind):
                while rep_ind[ri]>2 and rep_ind[ri]%3 ==1 and 2<= num_del:
                    rep_ind[ri]-= 2
                    num_del -= 2 
                    corrections+=2
                if rep_ind[ri] < 3:
                    del rep_ind[ri]
                else:
                    ri+=1
            #print(rep_ind)
            for c in rep_ind:
                while c>2 and c%3==2 and 3<=num_del:
                    c -=3
                    num_del -= 3
                    corrections +=3
                num_rp += c//3   
            #print(corrections)
            #print(num_rp)
            return corrections + num_del + max(num_rp,num_replace) 
__________________________________________________________________________________________________
