__________________________________________________________________________________________________
32ms
class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        if len(strs)==0 or '' in strs:
            return ''
        if len(set(strs))==1:
            return strs[0]
        maxlen=min([len(e) for e in strs])
        check = 1
        i=0
        while (check !=0 & i<maxlen):
            sub=[e[:i] for e in strs]
            if len(set(sub))==1:
                i+=1
            else:
                check = 0
        return strs[0][:i-1]            
__________________________________________________________________________________________________
36ms
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return '' 
        min_l = min(list(map( lambda x: len(x), strs))) 
        res = '' 
        for i in range(min_l):
            sym = strs[0][i] 
            for s in strs:
                if s[i]!= sym:
                    return res
            res += sym
        return res
__________________________________________________________________________________________________
40ms
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs or len(strs) == 0:
            return ""
        for i, cin in enumerate(strs[0]):
            for s in strs[1:]:
                if i >= len(s):
                    return strs[0][:i]
                if cin != s[i] :
                    return strs[0][:i]


        return strs[0][:]             
__________________________________________________________________________________________________
12224 kb
class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        if not strs:
            return ""
        
        longest = strs[0]
        for i in range(1, len(strs)):
            longest = self.shared_prefix(longest, strs[i])
            if longest == "":
                break

        return longest
            
    def shared_prefix(self, str1, str2):
        prefix_length = min(len(str1), len(str2))  # Assume it's as big as possible.
        for i, (char1, char2) in enumerate(zip(str1, str2)):
            if char1 != char2:
                prefix_length = i
                break
        return str1[:prefix_length]
__________________________________________________________________________________________________
12244 kb 
class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        _len = len(strs)
        if _len == 0:
            return ''
        
        min_len = len(strs[0])
        for ii in range(1, _len):
            tmp = len(strs[ii]) 
            if tmp < min_len:
                min_len = tmp
        
        res = ''
        for ii in range(min_len):
            flag = True
            for str in strs:
                if str[ii] != strs[0][ii]:
                    flag = False
                    break
            if flag == True:
                res += strs[0][ii]
            else:
                break
        return res
__________________________________________________________________________________________________
