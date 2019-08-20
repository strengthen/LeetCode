__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def exclusiveTime(self, n: 'int', logs: 'List[str]') -> 'List[int]':
        res = [0] * n
        stack = []
   
        
        for log in logs:
            idx, start, time = log.split(':')
            idx, start, time = int(idx), start == 'start', int(time)
            if start:
                if stack:
                    res[stack[-1]] += time - last_time                    
                stack.append(idx)
                last_time = time
            else:
                stack.pop()
                res[idx] += time - last_time + 1
                last_time = time + 1
        return res                 
__________________________________________________________________________________________________
sample 12952 kb submission
from collections import deque

class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stack = deque()         # task and total time accumulated so far and whether it is cut off
        times = [0] * n
        last_time = 0
        for log in logs:
            task, state, time = log.split(':')
            task = int(task)
            time = int(time)
            is_end = state == 'end'
            if not stack:
                stack.append([task, 0, False])
            elif is_end:
                times[task] += stack[-1][1] + time - last_time
                if not stack[-1][2]:
                    times[task] += 1
                del stack[-1]
            else: # start
                stack[-1][1] += time - last_time
                if stack[-1][2]:  # if cut off, last time is closing, which takes up 1, so subtract it
                    stack[-1][1] -= 1
                stack[-1][2] = True
                stack.append([task, 0, False])
            last_time = time
        return times
__________________________________________________________________________________________________
