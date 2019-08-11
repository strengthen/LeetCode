__________________________________________________________________________________________________
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        s1 = dict()
        for i, ch in enumerate(str1):
            if ch not in s1:
                s1[ch] = list()
            s1[ch].append(i)
        s2 = dict()
        for i, ch in enumerate(str2):
            if ch not in s2:
                s2[ch] = list()
            s2[ch].append(i)
        if len(s1) == len(s2) == 26 and str1 != str2:
            return False

        for k, v in s1.items():
            pivot = str2[v[0]]
            for pos in v:
                if str2[pos] != pivot:
                    return False

        return True

__________________________________________________________________________________________________

__________________________________________________________________________________________________
