__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        count = i = 0 
        res = []
        for j,v in enumerate(S):
            count = count + 1 if v == '1' else count - 1
            if count == 0:
                res.append('1' + self.makeLargestSpecial(S[i+1:j])+'0')
                i=j+1
        return ''.join(sorted(res)[::-1])
__________________________________________________________________________________________________
sample 13076 kb submission
class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        sub_spec = []
        largest_special = ""
        
        for spec in self.find_special(S):
            sub_special = ""
            if len(spec) <= 4:
                sub_special = spec
            else:
                sub_special = spec[0] + self.makeLargestSpecial(spec[1:len(spec)]) + spec[-1]
            sub_spec.append(sub_special)
    
        sub_spec.sort()
        for spec in reversed(sub_spec):
            largest_special += spec
        
        return largest_special
            
            
    def find_special(self, S):
        c = 0
        total_sum = 0
        specials = []
        cur = ""
        for c in S:
            cur += c
            if c == "1":
                total_sum += 1
            elif c == "0":
                total_sum -= 1
            if total_sum == 0:
                specials.append(str(cur))
                cur = ""

        return specials
__________________________________________________________________________________________________
