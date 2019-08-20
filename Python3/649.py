__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        rc, dc = 0, 0
        while len(set(senate)) > 1:
            new = ''
            for i in senate:
                if i == 'R':
                    if rc >= 0:
                        rc, dc = 0, dc - 1
                        new += i
                    else: rc += 1
                else:
                    if dc >= 0:
                        rc, dc = rc - 1, 0
                        new += i
                    else: dc += 1
                # print("rc:", rc, " dc:", dc)
            senate = new
            # print(senate)
        if senate[0] == 'R':
            return "Radiant"
        else:
            return "Dire"
__________________________________________________________________________________________________
sample 13232 kb submission
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        queue = collections.deque()
        people, bans = [0, 0], [0, 0]
        
        for person in senate:
            x = person == 'R'
            people[x] += 1
            queue.append(x)
        
        while all(people):
            x = queue.popleft()
            people[x] -= 1
            
            if bans[x]:
                bans[x] -= 1
            else:
                bans[x^1] += 1
                queue.append(x)
                people[x] += 1
        
        return 'Radiant' if people[1] else 'Dire'
__________________________________________________________________________________________________
