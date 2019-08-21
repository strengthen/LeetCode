__________________________________________________________________________________________________
sample 536 ms submission
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people = sorted(people)
        ans, start, end = 0, 0, len(people)-1
        while start < end:
            if people[end] + people[start] <= limit:
                start += 1
            ans += 1
            end -= 1
        return ans+1 if start == end else ans
__________________________________________________________________________________________________
sample 17560 kb submission
class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        
        count = 0
        p, q = 0, len(people) - 1
        while p <= q:
            if people[p] + people[q] <= limit:
                p += 1
                q -= 1
            else:
                q -= 1
            count += 1
        return count
__________________________________________________________________________________________________
