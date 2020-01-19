__________________________________________________________________________________________________
sample 224 ms submission
class Solution:
  def maxSumDivThree(self, nums: List[int]) -> int:
    sm = sum(nums)
    x = sm % 3
    if x == 0: return sm
    heapq.heapify(nums)
    A = []
    while nums:
      a = heapq.heappop(nums)
      a3 = a % 3
      if a3:
        if a3 == x:
          if len(A) < 2 or a <= A[0] + A[1]:
            return sm - a
          else:
            return sm - A[0] - A[1]
        else:
          A.append(a)
    return sm - sum(A[:len(A) % 3])
__________________________________________________________________________________________________
sample 236 ms submission
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        total = sum(nums)
        remainder = total % 3
        if remainder == 0:
            return total

        nums.sort()
        one, two = [], []
        for num in nums:
            remainder1 = num % 3
            if remainder1 == 1:
                one.append(num)
            elif remainder1 == 2:
                two.append(num)

            if len(one) >= 2 and len(two) >= 2:
                break

        tmp1 = tmp2 = float('inf')
        if remainder == 1:
            if one:
                tmp1 = one[0]
            if len(two) > 1:
                tmp2 = two[0] + two[1]
        else:
            if len(one) > 1:
                tmp1 = one[0] + one[1]
            if two:
                tmp2 = two[0]
        return total - min(tmp1, tmp2)  
__________________________________________________________________________________________________
