__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def removeDuplicates(self, S: str) -> str:
        dup_lst = ['aa','bb','cc','dd','ee','ff','gg','hh','ii','jj','kk','ll','mm','nn','oo','pp','qq','rr','ss','tt','uu','vv','ww','xx','yy','zz']
        if len(S) == 1:
            return S
        l_prev = len(S)
        while True:
            # print(S)
            for dup in dup_lst:
                S = S.replace(dup,'')
            # print(S)
            if l_prev == len(S):
                break
            else:
                l_prev = len(S)
        return S
__________________________________________________________________________________________________
class Solution:
    def removeDuplicates(self, S: str) -> str:
        replace_dict = {'aa': '',
                         'bb': '',
                         'cc': '',
                         'dd': '',
                         'ee': '',
                         'ff': '',
                         'gg': '',
                         'hh': '',
                         'ii': '',
                         'jj': '',
                         'kk': '',
                         'll': '',
                         'mm': '',
                         'nn': '',
                         'oo': '',
                         'pp': '',
                         'qq': '',
                         'rr': '',
                         'ss': '',
                         'tt': '',
                         'uu': '',
                         'vv': '',
                         'ww': '',
                         'xx': '',
                         'yy': '',
                         'zz': ''}

        length_previous = -1
        length = len(S)
        while length != length_previous:
            for word, initial in replace_dict.items():
                S = S.replace(word, initial)
            length_previous = length
            length = len(S)
        return S
__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def removeDuplicates(self, S: str) -> str:
        while True:
            blen=len(S)
            for i in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']:
                sp=i*2
                Sl=S.split(sp)
                S="".join(Sl)
            alen=len(S)
            if blen==alen:
                break
        return S
__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def removeDuplicates(self, S: str) -> str:
        ref=[chr(i) for i in range(97,97+26)]
        ref=[x*2 for x in ref]
        def helper_inS(ref):
            for y in ref:
                if y in S:
                    return 1
            return 0
        while S:
            for y in ref:
                if y in S:
                    S=S.replace(y,'')
            if helper_inS(ref)==0:
                break
        return S