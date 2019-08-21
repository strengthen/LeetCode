__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B): return False
        if A == B and len(set(A)) < len(A): return True
        diff = [(a, b) for a, b in zip(A, B) if a != b]
        return len(diff) == 2 and diff[0] == diff[1][::-1]
__________________________________________________________________________________________________
sample 13080 kb submission
class Solution(object):
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B): return False
        
        # 兩個字串相等, 且字串中有重複的字元(swap後字串不變)
        if A == B and len(set(A)) < len(A): return True
        
        # ["abcd", "badc"], #false
        # dif = [('a', 'b'), ('b', 'a'), ('c', 'd'), ('d', 'c')]
        # 唯一一組, 且swap後吻合 -> True
        dif = [(a, b) for a, b in zip(A, B) if a != b]
        #print(dif)
        return len(dif) == 2 and dif[0] == dif[1][::-1]
__________________________________________________________________________________________________
