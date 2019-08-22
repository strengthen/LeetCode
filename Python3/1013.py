__________________________________________________________________________________________________
sample 336 ms submission
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total_sum = sum(A)
        if total_sum%3!=0:
            return False
        part_sum = total_sum/3
        part_num = 0
        tmp_sum =0
        for a in A:
            tmp_sum+=a
            if tmp_sum==part_sum:
                part_num +=1
                tmp_sum=0
                if part_num==2:
                    return True
        return False
__________________________________________________________________________________________________
sample 17432 kb submission
class Solution:
     def canThreePartsEqualSum(self, A):
        s = sum(A)
        if s % 3 != 0:
            return False
        s /= 3
        targets = [2 * s, s]
        acc = 0
        for a in A:
            acc += a
            if acc == targets[-1]:
                targets.pop()
            if not targets:
                return True
        return False
__________________________________________________________________________________________________
