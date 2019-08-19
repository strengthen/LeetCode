__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 4:
            return False
        total = sum(nums)
        if total % 4:
            return False
        
        target = total // 4
        
        def find(nums):
            minset = set()
            q = collections.deque()
            q.append(([0], nums[0]))
            while q:
                parts, curr = q.popleft()
                if curr == target:
                    minset = set(parts)
                    break
                for i in range(parts[-1]+1, len(nums)):
                    if curr + nums[i] <= target:
                        q.append((parts + [i], curr + nums[i]))
            return [nums[k] for k in range(len(nums)) if k not in minset]
        
        nums.sort(reverse = True)
        if nums[0] > target:
            return False
        for _ in range(3):
            before = len(nums)
            nums = find(nums)
            after = len(nums)
            if before == after:
                return False
        return True    
__________________________________________________________________________________________________
sample 13088 kb submission
class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        
        def dfs(nums, pos, target):
            if pos == len(nums): return True
            for i in range(4):
                if target[i] >= nums[pos]:
                    target[i] -= nums[pos]
                    if dfs(nums, pos+1, target): return True
                    target[i] += nums[pos]
            return False
        if len(nums) < 4 : return False
        numSum = sum(nums)
        nums.sort(reverse=True)
        if numSum % 4 !=0: return False
        target = [numSum/4] * 4;
        return dfs(nums, 0, target)
__________________________________________________________________________________________________
