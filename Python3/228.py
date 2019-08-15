__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def convert_list(self, master_list):
        for i, entry in enumerate(master_list):
            if len(entry) == 1:
                master_list[i] = str(entry[0])
            else:
                first_num = entry[0]
                last_num = entry[-1]
                entry_str = str(first_num) + "->" + str(last_num)
                master_list[i] = entry_str
        return master_list
    
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return nums

        nums.sort()
        master_list = []
        for i,num in enumerate(nums):
            if i == 0:
                run_list = [num]

            else: 
                if num == prev_num + 1:
                    run_list.append(num)
                else:
                    master_list.append(run_list)
                    run_list = [num]
            
            prev_num = num
        
        # it is possible at this point, the last chunk is not 
        # added to the list yet. Do a check and add it. 
        if not master_list:
            master_list.append(run_list)
        elif master_list[-1][0] != run_list[0]:
            master_list.append(run_list)

        return self.convert_list(master_list)
__________________________________________________________________________________________________
sample 12972 kb submission
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        
        l, start, ans = len(nums), 0, []
        for i in range(1, l):
            if nums[i] - nums[i-1] != 1:
                span = str(nums[start]) + ('->' + str(nums[i-1]) if i-1 != start else '')
                ans.append(span)
                start = i
        span = str(nums[start]) + ('->' + str(nums[-1]) if l-1 != start else '')
        ans.append(span)
        return ans
__________________________________________________________________________________________________
