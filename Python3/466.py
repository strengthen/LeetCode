__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        start = {} # s2_idx : s1_round, s2_round
        s1_round, s2_round, s2_idx = 0, 0, 0
        while s1_round < n1:
            s1_round += 1
            for ch in s1:
                if ch == s2[s2_idx]:
                    s2_idx += 1
                    if s2_idx == len(s2):
                        s2_round += 1
                        s2_idx = 0
            if s2_idx in start:
                prev_s1_round, prev_s2_round = start[s2_idx]
                circle_s1_round, circle_s2_round = s1_round - prev_s1_round, s2_round - prev_s2_round
                res = (n1 - prev_s1_round) // circle_s1_round * circle_s2_round
                left_s1_round = (n1 - prev_s1_round) % circle_s1_round + prev_s1_round
                for key, val in start.items():
                    if val[0] == left_s1_round:
                        res += val[1]
                        break
                return res // n2
            else:
                start[s2_idx] = (s1_round, s2_round)
        return s2_round // n2
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def getMaxRepetitions(self, s1: 'str', n1: 'int', s2: 'str', n2: 'int') -> 'int':
        if not s1 or n1 == 0: return 0
        if not s2 or n2 == 0: return None
        i1, i2 = 0, 0
        len1, len2 = len(s1), len(s2)
        l = [0] # l[1]=n means [s1,1] contains [s2,n]
        c = 0
        seen_i1 = {len1-1: [0, 0]}
        while True:
            if s1[i1] == s2[i2]:
                i2 += 1
                if i2 == len2:
                    # one complete s2 contained
                    i2 = 0
                    c += 1 # count number of s2 contained
                    # check if same i1 was seen before
                    if i1 in seen_i1:
                        last_n1, last_c = seen_i1[i1]
                        repeat_a = len(l) - last_n1
                        repeat_b = c - last_c
                        break
                    else:
                        # store the number of s1 used anc c
                        seen_i1[i1] = [len(l), c]
            i1 += 1
            if i1 == len1:
                # one complete s1 used
                i1 = 0
                # store number of s2 contained
                l.append(c)
                if len(l) - 1 == n1:
                    # repeat used up
                    return c
        # l[last_n1] is overhead before repeat starts
        # the repeat is between [last_n1+1 ~ n1]
        total_s2 = l[last_n1] +  int((n1 - last_n1) / repeat_a * repeat_b)
        # compute M
        res = int(total_s2 / n2)
        return res
__________________________________________________________________________________________________
