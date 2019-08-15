__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0,1]
        leng = 2
        while num + 1 > leng:
            dp.extend([i+1 for i in dp])
            leng *= 2
        return dp[:num+1]
__________________________________________________________________________________________________
sample 15648 kb submission
class Solution:
    def countBits(self, num: int) -> List[int]:
        if num == 0: return [0]

        record = [0, 1]
        i = 2

        while i <= num:
            recordCopy = record[:]
            for bitCount in recordCopy:
                record.append(1 + bitCount)

                i += 1

                if i > num: break

        return record
__________________________________________________________________________________________________
