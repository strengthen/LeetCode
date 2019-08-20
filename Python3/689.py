__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:

        # best results (indexes) to start from
        best_1 = 0
        best_2 = [0, k]
        best_3 = [0, k, k*2]

        # sum for each sliding window
        sum_1 = sum(nums[0:k])
        sum_2 = sum(nums[k:k*2])
        sum_3 = sum(nums[k*2:k*3])

        # Sums of combined best windows
        best_sum_1 = sum_1
        best_sum_2 = sum_1 + sum_2
        best_sum_3 = sum_1 + sum_2 + sum_3

        # starting indexes
        i_1 = 1
        i_2 = k + 1
        i_3 = k*2 + 1

        while i_3 <= len(nums) - k:

            # Update the three sliding windows - subtract the left; add the right
            sum_1 = sum_1 - nums[i_1 - 1] + nums[i_1 + k - 1]
            sum_2 = sum_2 - nums[i_2 - 1] + nums[i_2 + k - 1]
            sum_3 = sum_3 - nums[i_3 - 1] + nums[i_3 + k - 1]

            # Best first window
            if sum_1 > best_sum_1:
                best_sum_1 = sum_1
                best_1 = i_1

            # Best two windows
            if best_sum_1 + sum_2 > best_sum_2:
                best_sum_2 = best_sum_1 + sum_2
                best_2 = [best_1, i_2]

            # print(i_1, best_2)


            # Best three windows
            if best_sum_2 + sum_3 > best_sum_3:
                best_sum_3 = best_sum_2 + sum_3
                best_3 = best_2 + [i_3]


            # print(i_1, best_3)


            # move forwards
            i_1 += 1
            i_2 += 1
            i_3 += 1

        return best_3
__________________________________________________________________________________________________
sample 15032 kb submission
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        # Best single, double, and triple sequence found so far
        bestSeq = 0
        bestTwoSeq = [0, k]
        bestThreeSeq = [0, k, k*2]

        # Sums of each window
        seqSum = sum(nums[0:k])
        seqTwoSum = sum(nums[k:k*2])
        seqThreeSum = sum(nums[k*2:k*3])

        # Sums of combined best windows
        bestSeqSum = seqSum
        bestTwoSum = seqSum + seqTwoSum
        bestThreeSum = seqSum + seqTwoSum + seqThreeSum

        # Current window positions
        seqIndex = 1
        twoSeqIndex = k + 1
        threeSeqIndex = k*2 + 1
        while threeSeqIndex <= len(nums) - k:
            # Update the three sliding windows
            seqSum = seqSum - nums[seqIndex - 1] + nums[seqIndex + k - 1]
            seqTwoSum = seqTwoSum - nums[twoSeqIndex - 1] + nums[twoSeqIndex + k - 1]
            seqThreeSum = seqThreeSum - nums[threeSeqIndex - 1] + nums[threeSeqIndex + k - 1]
            
            # Update best single window
            if seqSum > bestSeqSum:
                bestSeq = seqIndex
                bestSeqSum = seqSum

            # Update best two windows
            if seqTwoSum + bestSeqSum > bestTwoSum:
                bestTwoSeq = [bestSeq, twoSeqIndex]
                bestTwoSum = seqTwoSum + bestSeqSum

            # Update best three windows
            if seqThreeSum + bestTwoSum > bestThreeSum:
                bestThreeSeq = bestTwoSeq + [threeSeqIndex]
                bestThreeSum = seqThreeSum + bestTwoSum

            # Update the current positions
            seqIndex += 1
            twoSeqIndex += 1
            threeSeqIndex += 1

        return bestThreeSeq
__________________________________________________________________________________________________
