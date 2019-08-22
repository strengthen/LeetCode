__________________________________________________________________________________________________
sample 796 ms submission
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        # makes a list of people that trust people
        # if True then they trust, if False they don't trust anyone
        count = [0] * (N + 1)
        for i,j in trust:
            count[i] -= 1
            count[j] += 1
        for i in range(1, N+1):
            if count[i] == N - 1:
                return i
        return -1            
__________________________________________________________________________________________________
sample 16228 kb submission
from collections import defaultdict
# Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
class Solution:
    def findJudge(self, N, trust):
        # create trust dictionary {person: set(person who trusts)}
        trust_dict = defaultdict(set)

        for connection in trust: 
            trust_dict[connection[0]].add(connection[1])

        for i in range(1, N+1):
            if i not in trust_dict:
                trust_dict[i] = set()

        candidates = set()
        for person, trusted in trust_dict.items():
            if not trusted:
                candidates.add(person)

        # check if candidates is empty
        if len(candidates) == 0:
            return -1

        # check if candidates are more than two
        if len(candidates) >= 2:
            return -1

        candidate = list(candidates)[0]
        # re-evaluate the candidate by looping through trust dict
        for person, trusted in trust_dict.items():
            if person == candidate:
                continue

            # return -1 if the condition property 2 doesn't meet
            if not candidate in trusted:
                return -1

        # return candidate
        return candidate
__________________________________________________________________________________________________
