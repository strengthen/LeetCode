__________________________________________________________________________________________________
sample 428 ms submission
# not my submission
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        from collections import Counter
        counter = Counter(nums)
        count2ref = Counter()
        for v, c in counter.items():
            count2ref[c] += 1

        i = len(nums) - 1
        def dec_count(count):
            count2ref[count] -= 1
            if count2ref[count] == 0:
                count2ref.pop(count)

        while i > 0:
            if len(count2ref.keys()) == 2:
                keys2values = list(count2ref.items())
                keys2values.sort()
                if keys2values[1][0] - keys2values[0][0] == 1 and keys2values[1][1] == 1: return i + 1
                elif keys2values[0][0] == 1 and keys2values[0][1] == 1: return i + 1
            elif len(count2ref.keys()) == 1:
                keys2values = list(count2ref.items())
                if keys2values[0][1] > 1 and keys2values[0][0] == 1: return i + 1
                elif keys2values[0][0] > 1 and keys2values[0][1] == 1: return i + 1


            counter[nums[i]] -= 1
            if counter[nums[i]] == 0:
                counter.pop(nums[i])
                dec_count(1)
            else:
                dec_count(counter[nums[i]] + 1)
                count2ref[counter[nums[i]]] += 1
            i -= 1
        return 2
__________________________________________________________________________________________________
sample 452 ms submission
class Solution:

  def maxEqualFreq(self, nums: List[int]) -> int:
    from collections import Counter
    counter = Counter(nums)
    count2ref = Counter()
    for v, c in counter.items():
      count2ref[c] += 1

    i = len(nums) - 1

    def dec_count(count):
      count2ref[count] -= 1
      if count2ref[count] == 0:
        count2ref.pop(count)

    while i > 0:
      if len(count2ref.keys()) == 2:
        keys2values = list(count2ref.items())
        keys2values.sort()
        if keys2values[1][0] - keys2values[0][0] == 1 and keys2values[1][1] == 1:
          return i + 1
        elif keys2values[0][0] == 1 and keys2values[0][1] == 1:
          return i + 1
      elif len(count2ref.keys()) == 1:
        keys2values = list(count2ref.items())
        if keys2values[0][1] > 1 and keys2values[0][0] == 1:
          return i + 1  # example: [1,2,3,4,5]
        elif keys2values[0][0] > 1 and keys2values[0][1] == 1:
          return i + 1  # example: [1,1,1,1,1]

      counter[nums[i]] -= 1
      if counter[nums[i]] == 0:
        counter.pop(nums[i])
        dec_count(1)
      else:
        dec_count(counter[nums[i]] + 1)
        count2ref[counter[nums[i]]] += 1
      i -= 1
    return 2
__________________________________________________________________________________________________
