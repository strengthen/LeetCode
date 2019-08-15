__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for t in range(1, target+1):
            for v in nums:
                if t >= v:
                    dp[t] += dp[t-v]
        return dp[target]
__________________________________________________________________________________________________
sample 13304 kb submission
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # Check whether the input array is None or empty
        if not nums:
            return 0
        # Assumption: nums only contains distinct numbers, nums[i] > 0, and target > 0

        # DFS / Backtracking
        # # -> We need to sort nums first.
        # nums.sort()

        # self._perm_count = 0
        # self._combination_sum4_helper([], 0, nums, target)
        # return self._perm_count

        # Essentially, this is a knapsack problem (exact version) similar to 322-Coin Change and 518-Coin Change 2.
        # => DP solution

        # Initialization
        # subproblems[i]: Number of possible combinations that add up to i
        subproblems = [0] * (target + 1)
        subproblems[0] = 1
        # Bottom-up calculation
        for curr_target in range(1, target + 1):
            num_of_combs = 0
            # Let each number, in turn, be the last number
            for num in nums:
                # curr_target = num + a combination that adds up to (curr_target - num)
                remaining_target = curr_target - num
                if remaining_target >= 0:
                    num_of_combs += subproblems[remaining_target]
            subproblems[curr_target] = num_of_combs
        return subproblems[target]
__________________________________________________________________________________________________
