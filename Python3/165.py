__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = version1.split(".")
        version2 = version2.split(".")
        n1 = len (version1)
        n2 = len (version2)
        
        diff = abs (n1 - n2)
        
        if len (version1) < len (version2):
            version1 = version1 + [0] * diff
        elif len (version1) > len (version2):
            version2 = version2 + [0] * diff
        
        for i in range(len(version1)):
            if int(version1[i]) > int(version2[i]):
                return 1
            elif int(version1[i]) < int(version2[i]):
                return -1
        return 0
__________________________________________________________________________________________________
sample 13068 kb submission
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1_parts = version1.split('.')
        version2_parts = version2.split('.')
        while version1_parts and int(version1_parts[-1]) == 0:
            del version1_parts[-1]
        while version2_parts and int(version2_parts[-1]) == 0:
            del version2_parts[-1]
        print(version1_parts, version2_parts)
        length = min(len(version1_parts), len(version2_parts))
        for i in range(length):
            if int(version1_parts[i]) > int(version2_parts[i]):
                return 1
            elif int(version1_parts[i]) < int(version2_parts[i]):
                return -1
        return 1 if len(version1_parts) > len(version2_parts) else -1 if \
            len(version1_parts) < len(version2_parts) else 0
__________________________________________________________________________________________________
