__________________________________________________________________________________________________
sample 692 ms submission
from collections import defaultdict
from bisect import bisect_right as br
class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.counter = defaultdict(int)
        self.curr_winner = []
        self.times = times
        
        curr_max = 0
        for p in persons:
            self.counter[p] += 1
            if self.counter[p] >= curr_max:
                curr_max = self.counter[p]
                self.curr_winner.append(p)
            else:
                self.curr_winner.append(self.curr_winner[-1])

    def q(self, t: int) -> int:
        i = br(self.times, t)
        return self.curr_winner[i-1]        

# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
__________________________________________________________________________________________________
sample 700 ms submission
class TopVotedCandidate:

    def __init__(self, persons, times):
        votes = collections.defaultdict(int)
        winner = 0
        self.winners = [None] * len(times)
        self.times = times
        for i, person in enumerate(persons):
            votes[person] += 1 
            if votes[person] >= votes[winner]:
                winner = person
            self.winners[i] = winner

    def q(self, t):
        return self.winners[bisect.bisect(self.times, t) - 1]
__________________________________________________________________________________________________
