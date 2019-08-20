__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
    
        d.sort(key=lambda x:(-len(x),x))
        def help(s,b):
            i=0
            k=0
            
            for i in b:
                k=s.find(i,k)+1
                if k==0:
                    return False
        
            return True
        for i in d:
            if help(s,i):
                return i
        return ''
__________________________________________________________________________________________________
sample 14384 kb submission
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        def is_deleting_word(s: str, ds: str) -> bool:
            s_set = set(list(s))
            ds_set = set(list(ds))
            if ds_set - s_set:
                return False
            for dsc in ds:
                if dsc not in s or not s:
                    return False
                s = s[s.index(dsc) + 1:]
            return True

        result = ''
        for ds in d:
            if is_deleting_word(s, ds):
                if len(ds) > len(result):
                    result = ds
                elif len(ds) == len(result) and ds < result:
                    result = ds
        return result
__________________________________________________________________________________________________
