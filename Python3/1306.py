__________________________________________________________________________________________________
sample 216 ms submission
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        q = [start]
        visited = [False] * len(arr)
        visited[start] = True
        while q:
            curIndex = q.pop(0)
            if arr[curIndex] == 0:
                return True
            visited[curIndex] = True
            for nextIndex in [curIndex+arr[curIndex], curIndex-arr[curIndex]]:
                if nextIndex < 0 or nextIndex >= len(arr) or visited[nextIndex]:
                    continue
                q.append(nextIndex)
        return False
__________________________________________________________________________________________________
sample 220 ms submission
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        # BFS
        queue = collections.deque()
        queue.append(start)
        seen = set()
        seen.add(start)
        while queue:
            cur_index = queue.popleft()
            if arr[cur_index] == 0:
                return True
            if 0 <= cur_index + arr[cur_index] < len(arr) and cur_index + arr[cur_index] not in seen:
                queue.append(cur_index + arr[cur_index])
                seen.add(cur_index + arr[cur_index])
            if 0 <=  cur_index - arr[cur_index] < len(arr) and cur_index - arr[cur_index] not in seen:
                queue.append(cur_index - arr[cur_index])
                seen.add(cur_index - arr[cur_index])
        return False
__________________________________________________________________________________________________
