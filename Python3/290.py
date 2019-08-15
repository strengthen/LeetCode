__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def wordPattern(self, pattern, string):
        store = {}
        done_list = []
        str_list = string.split()
        if len(str_list) != len(pattern) or string == "":
            return False
        for word_pair in zip(pattern,string.split()):
            if word_pair[0] in store:
                if store[word_pair[0]] != word_pair[1]:
                    return False
            else:
                if  word_pair[1] in done_list:
                    return False
                store[word_pair[0]] = word_pair[1]
                done_list.append(word_pair[1])
        return True
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        a=str.split()
        if len(pattern)!=len(a):
            return False
        dic={}
        
        for i in range(len(pattern)):
            if pattern[i] not in dic:
                if a[i] in dic.values():
                    return False
                dic[ pattern[i] ] = a[i]
            elif dic[ pattern[i] ] !=a[i]:
                return False
                
        return True
__________________________________________________________________________________________________
