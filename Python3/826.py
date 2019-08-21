__________________________________________________________________________________________________
sample 392 ms submission
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        output = 0
        len_task = len(difficulty)
        all_task = list(sorted(zip(difficulty, profit)))
        track = 0
        best = 0
        for able in sorted(worker):
            while track < len_task:
                diff, price = all_task[track]
                if diff <= able:
                    if best <= price:
                        best = price
                    track += 1
                else:
                    break
            output += best
        return output
__________________________________________________________________________________________________
sample 14952 kb submission
class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker) -> int:
        rank = sorted(list(range(len(difficulty))), key=lambda i: difficulty[i])
        max_profit = 0
        p = 0
        w = sorted(worker)
        i = 0 
        for r in range(len(difficulty)+1):
            while i < len(worker) and  (r == len(difficulty) or  w[i] < difficulty[rank[r]]):
                p += max_profit
                i += 1
            if r < len(difficulty):
                max_profit = max(max_profit, profit[rank[r]])
        return p
__________________________________________________________________________________________________
